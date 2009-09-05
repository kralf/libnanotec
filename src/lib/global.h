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
  \file     global.h
  \author   Stefan Gachter <br>
            Autonomous Systems Laboratory <br>
            Swiss Federal Institute of Technology (ETHZ) <br>
            Zurich, Switzerland.
  \version  1.0
  \brief
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>

#define NANOTEC_FALSE                             0
#define NANOTEC_TRUE                              1

#define NANOTEC_MAX_NAME_LENGTH                   256

#define NANOTEC_INVALID_HANDLE                    -1

#define NANOTEC_NOPARITY                          0
#define NANOTEC_EVENPARITY                        1
#define NANOTEC_ONESTOPBIT                        1
#define NANOTEC_TWOSTOPBITS                       2

#define NANOTEC_BUFFER_SIZE                       1024
#define NANOTEC_MAX_COMMAND_SIZE                  1024

#define NANOTEC_WORK_MODE_POS                     1
#define NANOTEC_WORK_MODE_VEL                     2
#define NANOTEC_WORK_MODE_FLAG                    3
#define NANOTEC_WORK_MODE_CYCLE                   4

#define NANOTEC_POS_MODE_REL                      1
#define NANOTEC_POS_MODE_ABS                      2
#define NANOTEC_POS_MODE_INT                      3
#define NANOTEC_POS_MODE_EXT                      4

#define NANOTEC_STEP_SIZE_1_1                     1
#define NANOTEC_STEP_SIZE_1_2                     2
#define NANOTEC_STEP_SIZE_1_4                     4
#define NANOTEC_STEP_SIZE_1_5                     5
#define NANOTEC_STEP_SIZE_1_8                     8
#define NANOTEC_STEP_SIZE_1_10                    10

#define NANOTEC_MAX_INIT_POS                      90.0
#define NANOTEC_MAX_REL_STEPS                     16777215
#define NANOTEC_MAX_ABS_STEPS                     8388607

#define NANOTEC_STATUS_READY                      0x01
#define NANOTEC_STATUS_REF_REACHED                0x02
#define NANOTEC_STATUS_POS_ERROR                  0x04
#define NANOTEC_STATUS_TRAVEL_END                 0x08
#define NANOTEC_STATUS_MODE_POS                   0x10
#define NANOTEC_STATUS_MODE_VEL                   0x20
#define NANOTEC_STATUS_MODE_FLAG                  0x40

#define NANOTEC_SWITCH_DISABLE                    0
#define NANOTEC_SWITCH_RETURN                     1
#define NANOTEC_SWITCH_FORWARD                    2
#define NANOTEC_SWITCH_STOP                       3

#define NANOTEC_POLL_TIMEOUT                      1e-4
#define NANOTEC_SERIAL_TIMEOUT                    0.1
#define NANOTEC_CMD_TIMEOUT                       0.1

typedef uint8_t NANOTEC_BYTE;
typedef uint16_t NANOTEC_DWORD;

typedef int NANOTEC_HANDLE;

typedef enum {
  NANOTEC_MOTOR = 0,
  UNKNOWN_MOTOR = 99
} nanotec_motor_type_t;

typedef enum { NANOTEC_STEPMOTOR } nanotec_model_t;

typedef enum { NANOTEC_LEFT, NANOTEC_RIGHT } nanotec_dir_t;

double nanotec_deg_to_rad(double deg);
double nanotec_rad_to_deg(double rad);

int nanotec_round_angle(double theta);

double nanotec_get_time(void);

#endif
