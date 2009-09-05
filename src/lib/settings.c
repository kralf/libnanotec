/***************************************************************************
 *   Copyright (C) 2006 by Ralf Kaestner, Stefan Gaechter, Jan Weingarten  *
 *   Autonomous Systems Lab                                                *
 *   Swiss Federal Institute of Technology, Zurich                         *
 *   ralf.kaestner@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdio.h>
#include <string.h>

#include "settings.h"

void nanotec_settings_default(nanotec_settings_p settings, int motor_id) {
  settings->motor_id = motor_id;
  settings->type = NANOTEC_MOTOR;
  settings->step_res = nanotec_deg_to_rad(1.8);
  settings->step_freq = 100;

  strcpy(settings->device_name, "COM1");
  settings->baudrate = 19200;
  settings->databits = 8;
  settings->stopbits = NANOTEC_TWOSTOPBITS;
  settings->parity = NANOTEC_NOPARITY;

  settings->work_mode = NANOTEC_WORK_MODE_POS;
  settings->pos_mode = NANOTEC_POS_MODE_REL;
  settings->step_size = NANOTEC_STEP_SIZE_1_10;
  settings->direction = NANOTEC_LEFT;
  settings->min_velocity = nanotec_deg_to_rad(0.0);
  settings->max_velocity = nanotec_deg_to_rad(72.0);
  settings->acceleration = nanotec_deg_to_rad(360.0);
  settings->init_pos = nanotec_deg_to_rad(0.0);
}

void nanotec_settings_init(nanotec_settings_p settings, const char*
  device_name, int baudrate, float init_pos) {
  nanotec_settings_default(settings, 0);

  if (device_name != NULL)
    strcpy(settings->device_name, device_name);
  if (baudrate != 0)
    settings->baudrate = baudrate;
  if (init_pos != 0.0)
    settings->init_pos = init_pos;
}

void nanotec_settings_profile(nanotec_settings_p settings, float min_velocity,
  float max_velocity, float acceleration) {
  if (min_velocity != 0.0)
    settings->min_velocity = min_velocity;
  if (max_velocity != 0.0)
    settings->max_velocity = max_velocity;
  if (acceleration != 0.0)
    settings->acceleration = acceleration;
}

int nanotec_settings_check(nanotec_settings_p settings) {
  int result = NANOTEC_TRUE;

  if(settings->baudrate != 19200) {
    fprintf(stderr, "ERROR: baudrate of %d is not valid!\n",
      settings->baudrate);
    result = NANOTEC_FALSE;
  }

  if((settings->init_pos < 0.0) ||
    (settings->init_pos > NANOTEC_MAX_INIT_POS)) {
    fprintf(stderr, "ERROR: initial position %.2fdeg out of bounds\n",
	    nanotec_rad_to_deg(settings->init_pos));
    result = NANOTEC_FALSE;
  }

  return result;
}

int nanotec_settings_pos_to_steps(nanotec_settings_p settings, float pos) {
  return pos*settings->step_size/settings->step_res;
}

float nanotec_settings_steps_to_pos(nanotec_settings_p settings, int steps) {
  return steps*settings->step_res/settings->step_size;
}

int nanotec_settings_vel_to_freq(nanotec_settings_p settings, float vel) {
  return vel*settings->step_size/settings->step_res;
}

float nanotec_settings_freq_to_vel(nanotec_settings_p settings, int freq) {
  return freq*settings->step_res/settings->step_size;
}

int nanotec_settings_accel_to_ramp(nanotec_settings_p settings, float accel) {
  return settings->step_res/settings->step_size*settings->step_freq*1e3/accel;
}

float nanotec_settings_ramp_to_accel(nanotec_settings_p settings, int ramp) {
  return settings->step_res/settings->step_size*settings->step_freq*1e3/ramp;
}
