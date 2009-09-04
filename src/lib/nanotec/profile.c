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
  \file     profile.c
  \author   Ralf Kaestner <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#include <stdio.h>

#include "profile.h"

void nanotec_profile_default(nanotec_profile_p profile) {
  profile->pos_mode = NANOTEC_POS_MODE_REL;
  profile->step_size = NANOTEC_STEP_SIZE_1_10;

  profile->distance = nanotec_deg_to_rad(90.0);
  profile->min_velocity = nanotec_deg_to_rad(0.0);
  profile->max_velocity = nanotec_deg_to_rad(72.0);
  profile->acceleration = nanotec_deg_to_rad(360.0);
  profile->num_ops = 1;
  profile->change_dir = 0;
  profile->break_time = 0.1;

  profile->start_time = 0.0;
}

void nanotec_profile_init(nanotec_profile_p profile, float distance,
  float max_velocity, float acceleration) {
  nanotec_profile_default(profile);

  profile->distance = distance;
  profile->max_velocity = max_velocity;
  profile->acceleration = acceleration;
}

int nanotec_profile_start(nanotec_motor_p motor, nanotec_profile_p profile) {
  nanotec_motor_set_work_mode(motor, NANOTEC_WORK_MODE_POS);
  nanotec_motor_set_switch_behavior(motor, NANOTEC_SWITCH_DISABLE);
  nanotec_motor_set_pos_mode(motor, profile->pos_mode);
  nanotec_motor_set_step_size(motor, profile->step_size);

  nanotec_motor_set_position(motor, profile->distance);
  nanotec_motor_set_min_velocity(motor, profile->min_velocity);
  nanotec_motor_set_max_velocity(motor, profile->max_velocity);
  nanotec_motor_set_acceleration(motor, profile->acceleration);
  nanotec_motor_set_operations(motor, profile->num_ops);
  nanotec_motor_set_change_dir(motor, profile->change_dir);
  nanotec_motor_set_break(motor, profile->break_time);

  nanotec_motor_start(motor);
  profile->start_time = nanotec_get_time();
}

double nanotec_profile_get_time(nanotec_profile_p profile) {
  return 0.0;
}

float nanotec_profile_get_pos(nanotec_profile_p profile) {
  double time = nanotec_get_time();

  return 0.0;
}
