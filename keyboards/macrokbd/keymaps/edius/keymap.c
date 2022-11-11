/* Copyright 2022 Maximilian Ronniger <madhu1008@gmail.com>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

enum layer_name {
  _EDIUS,
  _EDIUS2,
  _EDIUS3,
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
  KC_0
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
      writePinLow(LED1);
      writePinLow(LED2);
      break;
    case _EDIUS2:
      writePinHigh(LED1);
      writePinLow(LED2);
      break;
    case _EDIUS3:
      writePinLow(LED1);
      writePinHigh(LED2);
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
        KC_N, KC_M, LCTL(KC_R), TO(_EDIUS2),
        LT(_MISC, LCTL(KC_Z)), KC_C, KC_A, KC_S
    ),
    [_EDIUS2] =  LAYOUT(
        KC_I, KC_O, KC_V, TO(_EDIUS3),
        KC_F7, KC_F8, LALT(KC_ENT), KC_DEL
    ),
    [_EDIUS3] = LAYOUT(
        LCTL(KC_T), LCTL(KC_P), LT(_MISC, KC_G),TO(_EDIUS),
        KC_COMMA, KC_DOT, KC_SPACE, LCTL(S(KC_S))
    ),
    [_MISC] = LAYOUT(
        _______, LALT(KC_G),_______, _______,
        _______, LCTL(KC_Y), _______,_______
    )
};



#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/* left encoder */
    if (index == 1) {
	switch(get_highest_layer(layer_state)){
           case 0: /* _EDIUS*/
             tap_code(clockwise ? KC_LEFT : KC_RIGHT);
             break;
	   case 1: /* _EDIUS2 */
           case 2: /* _EDIUS3 */
             if(clockwise){
               if(eid>=8){
                 eid=0;
               }
               else {
                 eid++;
               }
               tap_code16( C(edius[eid]) );
             } else {
               if(eid<=0){
                 eid=8;
               }
               else {
                 eid--;
               }
               tap_code16( C(edius[eid]) );
             }
             break;
           case 3: /* _MISC */
                tap_code(clockwise ? KC_MNXT : KC_MPRV);
                break;
	}
    }
    return true;
}
#endif

