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

/*!
  \file     profile.h
  \author   Ralf Kaestner <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#ifndef NANOTEC_PROFILE_H
#define NANOTEC_PROFILE_H

#include "motor.h"

typedef struct nanotec_profile_t {
  int pos_mode;
  int step_size;

  float distance;
  float min_velocity;
  float max_velocity;
  float acceleration;
  int num_ops;
  int change_dir;
  float break_time;

  double start_time;
} nanotec_profile_t, *nanotec_profile_p;

void nanotec_profile_default(nanotec_profile_p profile);
void nanotec_profile_init(nanotec_profile_p profile, float distance,
  float max_velocity, float acceleration);

int nanotec_profile_start(nanotec_motor_p motor, nanotec_profile_p profile);

double nanotec_profile_get_time(nanotec_profile_p profile);
float nanotec_profile_get_pos(nanotec_profile_p profile);

#endif
