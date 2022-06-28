/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

enum layer_name {
  _MEDIA,
  _BROWSER,
  _SYS,
  _MISC
};

// setup LED Pins as output
void keyboard_pre_init_user(void) {
    setPinOutput(LED1);
    setPinOutput(LED2);
}

/* update the leds with every layer change */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _MEDIA:
      writePinLow(LED1);
      writePinLow(LED2);
      break;
    case _BROWSER:
      writePinHigh(LED1);
      writePinLow(LED2);
      break;
    case _SYS:
      writePinLow(LED1);
      writePinHigh(LED2);
      break;
    case _MISC:
      writePinHigh(LED1);
      writePinHigh(LED2);
      break;
    default: // default fallback
      writePinLow(LED1);
      writePinLow(LED2);
      break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        KC_MUTE, KC_MRWD, KC_MPLY, KC_MFFD,
        TO(_BROWSER), KC_MPRV, KC_MSTP, KC_MNXT
    ),
    [_BROWSER] =  LAYOUT(
        KC_WWW_HOME, KC_WBAK, KC_WREF, KC_WFWD,
        TO(_SYS), KC_WSCH, KC_WSTP, KC_WFAV
    ),
    [_SYS] = LAYOUT(
        _______, LALT(KC_TAB), LSA(KC_TAB), _______,
        TO(_MISC), KC_3, C(KC_C), C(KC_V)
    ),
    [_MISC] = LAYOUT(
        _______, _______, _______, _______,
        TO(_MEDIA), KC_4, _______, _______
    )
};



#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/* left encoder */
    if (index == 0) {
	switch(get_highest_layer(layer_state)){
           case 0: /* _MEDIA*/
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
                break;
	   case 1: /* _BROWSER */
                tap_code16(clockwise ? C(KC_TAB) : S(C(KC_TAB)));
		/*
        	if (clockwise) {
            	    tap_code16(C(KC_TAB));
        	} else {
            	    tap_code16(S(C(KC_TAB)));
                }
		*/
                break;
           case 2: /* _SYS */
                tap_code(clockwise ? KC_PGUP : KC_PGDN);
                break;
           case 3: /* _MISC */
                tap_code(clockwise ? KC_MNXT : KC_MPRV);
                break;
	}
    }
/* right encoder */
    else if (index == 1) {
      tap_code(clockwise ? KC_PGUP : KC_PGDN);
    }

    return true;
}
#endif

