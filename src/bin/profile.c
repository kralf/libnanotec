/***************************************************************************
 *   Copyright (C) 2004 by Ralf Kaestner                                   *
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
#include <stdlib.h>

#include <nanotec.h>
#include <profile.h>

int main(int argc, char **argv) {
  if ((argc != 2) && (argc != 5)) {
    fprintf(stderr, "Usage: %s DEV [POS VEL ACCEL]\n", argv[0]);
    return -1;
  }

  nanotec_motor_t motor;
  nanotec_profile_t profile;

  if (argc == 5)
    nanotec_profile_init(&profile,
    nanotec_deg_to_rad(atof(argv[2])),
    nanotec_deg_to_rad(atof(argv[3])),
    nanotec_deg_to_rad(atof(argv[4])));
  else
    nanotec_profile_default(&profile);

  nanotec_init(&motor, 1, argv[1]);
  nanotec_profile_start(&motor, &profile);
  nanotec_motor_wait_status(&motor, NANOTEC_STATUS_READY);
  nanotec_close(&motor);

  return 0;
}
