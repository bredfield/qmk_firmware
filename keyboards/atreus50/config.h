/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0001
#define MANUFACTURER    benjamin
#define PRODUCT         Atreus50
#define DESCRIPTION     q.m.k. keyboard firmware for Atreus50

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

// wiring of each half
#define MATRIX_ROW_PINS { D1, D0, B4, B2 }
#define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4, B6, D3, D2, D4, C6, D7, E6 }

#define DEBOUNCE 5

#endif
