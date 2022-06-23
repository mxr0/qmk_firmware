/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _MEDIA,
  _SYS,
  _MISC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
        KC_MUTE, KC_MPLY, KC_MRWD, LT(1,KC_MFFD),
        TG(_MEDIA), C(KC_X), C(KC_C), C(KC_V)
    ),
    [_MEDIA] = LAYOUT(
        KC_MUTE, KC_MPLY, KC_MRWD, LT(1,KC_MFFD),
        TG(_SYS),   KC_A, KC_S, KC_D
    ),
    [_SYS] = LAYOUT(
        _______, _______, _______, _______,
        TG(_MISC), C(KC_X), C(KC_C), C(KC_V)
    ),
    [_MISC] = LAYOUT(
        _______, _______, _______, _______,
        TG(_BASE), _______, _______, _______
    )
};

/*
void keyboard_pre_init_user(void) {
    // Set our LED pins as output
    setPinOutput(LED1);
    setPinOutput(LED2);
}
*/

/* update the leds when the layer changes */
/*
uint32_t layer_state_set_user(uint32_t state) {
    switch (get_highest_layer(state)) {
    case _MEDIA:
      // set first led
      writePinHigh(LED1);
      writePinLow(LED2);
      break;
    case _SYS:
      // set secound led
      writePinLow(LED1);
      writePinHigh(LED2);
      break;
    case _MISC:
      // set both leds
      writePinHigh(LED1);
      writePinHigh(LED2);
      break;
    default: //  for any other layers, or the default layer
      // disable both leds
      writePinLow(LED1);
      writePinLow(LED2);
      break;
    }
    return state;
}
*/

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/* left encoder */
    if (index == 0) {
	switch(get_highest_layer(layer_state)){
	    case 0: /* _BASE */
        	if (clockwise) {
            	    tap_code(KC_MS_WH_UP);
        	} else {
            	    tap_code(KC_MS_WH_DOWN);
                }
                break;
           case 1: /* _MEDIA*/
        	if (clockwise) {
            	    tap_code(KC_VOLU);
        	} else {
            	    tap_code(KC_VOLD);
                }
                break;
           case 2: /* _SYS */
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
                break;
           case 3: /* _MISC */
        	if (clockwise) {
            	    tap_code(KC_MNXT);
        	} else {
            	    tap_code(KC_MPRV);
                }
                break;
	}
    }
/* right encoder */
    else if (index == 1) {
      if(clockwise) {
        tap_code(KC_PGUP);
      }
      else{
        tap_code(KC_PGDN);
      }
    }

    return true;
}
#endif

