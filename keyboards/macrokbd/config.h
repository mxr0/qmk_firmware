/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0666
#define DEVICE_VER      0x0001
#define MANUFACTURER    RBG
#define PRODUCT         macro_mini/rev1

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4


/* mode switch button+analog poti currently unused * /
#define DIRECT_PINS { A0, A1 }
*/

/* status LEDS */
#define LED1 F5
#define LED2 F4 

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, C6 }
#define MATRIX_COL_PINS { D7, E6, B4, B5 }

#define ENCODERS_PAD_A { B2, B1 }
#define ENCODERS_PAD_B { B6, B3 }
#define ENCODER_RESOLUTION  4

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
