/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

enum layer_name {
  _EDIUS,
  _EDIUS2,
  _SYS,
  _MISC
};

uint16_t edius[] = {
  KC_0,
  KC_1,
  KC_2,
  KC_3,
  KC_4,
  KC_5,
  KC_6,
  KC_7,
  KC_8,
  KC_9
};

int eid=0;

// setup LED Pins as output
void keyboard_pre_init_user(void) {
    setPinOutput(LED1);
    setPinOutput(LED2);
}

/* update the leds with every layer change */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _EDIUS:
      writePinHigh(LED1);
      writePinLow(LED2);
      break;
    case _EDIUS2:
      writePinLow(LED1);
      writePinHigh(LED2);
      break;
    case _SYS:
      writePinLow(LED1);
      writePinLow(LED2);
      break;
    case _MISC:
      writePinHigh(LED1);
      writePinHigh(LED2);
      break;
    default: // default fallback
      writePinHigh(LED1);
      writePinHigh(LED2);
      break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_EDIUS] = LAYOUT(
        KC_F7, KC_F8, LALT(KC_ENT), TO(_EDIUS2),
        KC_G, LALT(KC_G), LCTL(KC_T), LCTL(KC_P)
    ),
    [_EDIUS2] =  LAYOUT(
        KC_I, KC_O, LALT(KC_U), TO(_EDIUS),
        LCTL(S(KC_S)), LCTL(KC_C), LCTL(KC_V), LCTL(KC_R)
    ),
    [_SYS] = LAYOUT(
        _______, _______, _______,_______,
        _______, _______, _______,_______
    ),
    [_MISC] = LAYOUT(
        _______, _______, _______,_______,
        _______, _______, _______,_______
    )
};



#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/* left encoder */
    if (index == 1) {
	switch(get_highest_layer(layer_state)){
           case 0: /* _EDIUS*/
                if(clockwise){
                  if(eid>=9){
                    eid=0;
                  }
                  else {
                    eid++;
                  }
		  tap_code16( C(edius[eid]) );
                } else {
                  if(eid<=0){
                    eid=9;
                  }
                  else {
                    eid--;
                  }
		  tap_code16( C(edius[eid]) );
		}
                break;
	   case 1: /* _BROWSER */
                tap_code(clockwise ? KC_VOLD : KC_VOLU);
                break;
           case 2: /* _SYS */
                tap_code(clockwise ? KC_PGUP : KC_PGDN);
                break;
           case 3: /* _MISC */
                tap_code16(clockwise ? S(C(KC_TAB)) : C(KC_TAB));
                /*tap_code(clockwise ? KC_MNXT : KC_MPRV);*/
                break;
	}
    }
    return true;
}
#endif

