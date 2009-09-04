  /*!
 *
 * Copyright (C) 2006
 * Swiss Federal Institute of Technology, Zurich. All rights reserved.
 *
 * Developed at the Autonomous Systems Lab.
 * Visit our homepage at http://www.asl.ethz.ch/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

/*!
  \file     nanotec.c
  \author   Stefan Gachter, Jan Weingarten, Ralf Kaestner <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "nanotec.h"

int nanotec_init(nanotec_motor_p motor, int motor_id, const char* device_name) {
  int result = NANOTEC_FALSE;
  nanotec_settings_default(&motor->settings, motor_id);
  nanotec_settings_init(&motor->settings, device_name, 0, 0.0);

  fprintf(stderr, "INFO: motor type ... ");
  fprintf(stderr, "%s\n", (motor->settings.type == NANOTEC_MOTOR) ? "nanotec" :
    "unknown");
  if (nanotec_settings_check(&motor->settings) &&
    nanotec_motor_init(motor) &&
    nanotec_motor_stop(motor) &&
    nanotec_motor_test(motor)) {
    motor->type = motor->settings.type;
    return nanotec_setup(motor);
  }
  else
    fprintf(stderr, "ERROR: communication failed\n");

  return result;
}

int nanotec_close(nanotec_motor_p motor) {
  int result = NANOTEC_FALSE;

  if (nanotec_motor_close(motor))
    result = NANOTEC_TRUE;    

  return result;
}

int nanotec_setup(nanotec_motor_p motor) {
  if(!nanotec_motor_set_phase_current(motor))
    return NANOTEC_FALSE;    
  if(!nanotec_motor_set_current_reduction(motor))
    return NANOTEC_FALSE;    
  if(!nanotec_motor_set_clearance(motor))
    return NANOTEC_FALSE;

  if(!nanotec_motor_set_work_mode(motor, motor->settings.work_mode))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_pos_mode(motor, motor->settings.pos_mode))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_step_size(motor, motor->settings.step_size))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_direction(motor, motor->settings.direction))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_min_velocity(motor, motor->settings.min_velocity))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_max_velocity(motor, motor->settings.max_velocity))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_acceleration(motor, motor->settings.acceleration))
    return NANOTEC_FALSE;

  if(!nanotec_motor_set_operations(motor, 1))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_change_dir(motor, 0))
    return NANOTEC_FALSE;
  if(!nanotec_motor_set_break(motor, 0.1))
    return NANOTEC_FALSE;

  return NANOTEC_TRUE;
}

int nanotec_home(nanotec_motor_p motor, float init_pos) {
  nanotec_settings_t settings = motor->settings;

  nanotec_motor_set_min_velocity(motor, nanotec_deg_to_rad(0.0));
  nanotec_motor_set_max_velocity(motor, nanotec_deg_to_rad(18.0));

  nanotec_motor_set_pos_mode(motor, NANOTEC_POS_MODE_REL);
  nanotec_motor_set_direction(motor, NANOTEC_RIGHT);
  nanotec_motor_set_position(motor, nanotec_deg_to_rad(18.0));
  nanotec_motor_start(motor);
  nanotec_motor_wait_status(motor, NANOTEC_STATUS_READY);

  nanotec_motor_set_pos_mode(motor, NANOTEC_POS_MODE_INT);
  nanotec_motor_set_direction(motor, NANOTEC_LEFT);
  nanotec_motor_start(motor);
  nanotec_motor_wait_status(motor, NANOTEC_STATUS_REF_REACHED);
  usleep(4000000);

  nanotec_motor_set_pos_mode(motor, NANOTEC_POS_MODE_REL);
  nanotec_motor_set_direction(motor, NANOTEC_RIGHT);
  nanotec_motor_set_position(motor, init_pos);
  nanotec_motor_start(motor);
  nanotec_motor_wait_status(motor, NANOTEC_STATUS_READY);

  nanotec_motor_set_work_mode(motor, settings.work_mode);
  nanotec_motor_set_pos_mode(motor, settings.pos_mode);
  nanotec_motor_set_min_velocity(motor, settings.min_velocity);
  nanotec_motor_set_max_velocity(motor, settings.max_velocity);

  motor->settings = settings;
  motor->settings.init_pos = init_pos;
}
