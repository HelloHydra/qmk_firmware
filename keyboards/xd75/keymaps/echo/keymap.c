/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = { /* QWERTY */
  { KC_NO,               KC_NO,    KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,       KC_NO,      KC_NO,   KC_NO,   KC_NO   },
  { KC_TAB,               KC_Q,    KC_W,    KC_E,       KC_R,       KC_T,    KC_NO, KC_NO, KC_NO, KC_Y,   KC_U,        KC_I,       KC_O,    KC_P,    KC_QUOT },
  { MT(MOD_LCTL ,KC_ESC), KC_A,    KC_S,    KC_D,       KC_F,       KC_G,    KC_NO, KC_NO, KC_NO, KC_H,   KC_J,        KC_K,       KC_L,    KC_SCLN, KC_ENT  },
  { KC_LSFT,              KC_Z,    KC_X,    KC_C,       KC_V,       KC_B,    KC_NO, KC_NO, KC_NO, KC_N,   KC_M,        KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LCTL,              KC_LGUI, KC_LALT, MO(_RAISE), MO(_LOWER), KC_BSPC, KC_NO, KC_NO, KC_NO, KC_SPC, MO(_RAISE),  MO(_LOWER), KC_RALT, KC_RGUI, KC_RCTL },
 },
 
 [_LOWER] = { /* FUNCTION */ 
  { KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_F6   },
  { KC_TRNS, KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,     KC_TRNS, KC_TRNS, KC_TRNS, KC_F7,   KC_F8,      KC_F9,      KC_F10,  KC_F11,  KC_F12  },
  { KC_TRNS, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS,    KC_TRNS,    MO(_RAISE), MO(_LOWER), KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RAISE), MO(_LOWER), KC_TRNS, KC_TRNS, RESET   },
 },

 [_RAISE] = { /* FUNCTION */ 
  { KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_GRV,  KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_TRNS, KC_TRNS, KC_TRNS, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_TILD },
  { KC_TRNS, KC_1,       KC_2,       KC_3,       KC_4,       KC_5 ,      KC_TRNS, KC_TRNS, KC_TRNS, KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_TRNS },
  { KC_TRNS, KC_UNDS,    KC_MINS,    KC_PLUS,    KC_EQL,     KC_PIPE,    KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_LCBR,    KC_RCBR,    KC_LBRC, KC_RBRC, KC_TRNS },
  { KC_TRNS, KC_TRNS,    KC_TRNS,    MO(_RAISE), MO(_LOWER), KC_DEL,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RAISE), MO(_LOWER), KC_TRNS, KC_TRNS, RESET   },
 },
 
 [_FN] = { /* FUNCTION */ 
  { KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_CAPS, KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_TRNS },
  { KC_TRNS, KC_LALT,    KC_TRNS,    KC_TRNS,    MO(_LOWER), KC_DEL,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_RAISE), KC_TRNS, KC_TRNS, KC_RALT, RESET   },
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
