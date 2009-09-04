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
  \file     settings.h
  \author   Stefan Gachter, Jan Weingarten, Ralf Kaestner <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#ifndef NANOTEC_SETTINGS_H
#define NANOTEC_SETTINGS_H

#include "global.h"

typedef struct nanotec_settings_t {
  int motor_id;
  nanotec_model_t type;
  float step_res;
  int step_freq;

  char device_name[NANOTEC_MAX_NAME_LENGTH];
  int baudrate;
  NANOTEC_BYTE databits;
  NANOTEC_BYTE stopbits;
  NANOTEC_DWORD parity;

  int work_mode;
  int pos_mode;
  int step_size;
  nanotec_dir_t direction;
  float min_velocity;
  float max_velocity;
  float acceleration;
  float init_pos;
} nanotec_settings_t, *nanotec_settings_p;

void nanotec_settings_default(nanotec_settings_p settings, int motor_id);
void nanotec_settings_init(nanotec_settings_p settings, const char*
  device_name, int baudrate, float init_pos);
void nanotec_settings_profile(nanotec_settings_p settings, float min_velocity,
  float max_velocity, float acceleration);

int nanotec_settings_check(nanotec_settings_p settings);

int nanotec_settings_pos_to_steps(nanotec_settings_p settings, float pos);
float nanotec_settings_steps_to_pos(nanotec_settings_p settings, int steps);

int nanotec_settings_vel_to_freq(nanotec_settings_p settings, float vel);
float nanotec_settings_freq_to_vel(nanotec_settings_p settings, int freq);

int nanotec_settings_accel_to_ramp(nanotec_settings_p settings, float accel);
float nanotec_settings_ramp_to_accel(nanotec_settings_p settings, int ramp);

#endif
