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
 * This source code is based on the Carnegie Mellon Robot
 * Navigation Toolkit (CARMEN)
 *
 * CARMEN Copyright (c) 2002 Michael Montemerlo, Nicholas
 * Roy, Sebastian Thrun, Dirk Haehnel, Cyrill Stachniss,
 * and Jared Glover
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
  \file     global.c
  \author   Stefan Gachter <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double nanotec_deg_to_rad(double deg) {
  return deg*M_PI/180.0;
}

double nanotec_rad_to_deg(double rad) {
  return rad*180.0/M_PI;
}

int nanotec_round_angle(double theta) {
  if (theta >= 0)
    return (int)(theta+0.5);
  else
    return (int)(theta-0.5);
}

double nanotec_get_time(void) {
  struct timeval tv;
  double t;

  if (gettimeofday(&tv, NULL) < 0)
    fprintf(stderr,
    "Warning: get_time() encountered error in gettimeofday()!\n");
  t = tv.tv_sec+tv.tv_usec/1e6;

  return t;
}
