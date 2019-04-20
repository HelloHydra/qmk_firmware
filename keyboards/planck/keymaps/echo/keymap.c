/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_NO,   KC_DOT,  KC_RGUI, KC_RCTL
),

[_LOWER] = LAYOUT_planck_grid(
  _______, KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV ,
  KC_ENT,  KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, _______,
  _______, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), KC_MINS, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, KC_DOT,  _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
  _______, KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV ,
  KC_ENT,  KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, _______,
  _______, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), KC_MINS, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, KC_DOT,  _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  RESET,   _______, _______, KC_F14,  KC_F15,  _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 ,
  _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,
  _______, _______, _______, KC_MRWD, KC_MFFD, KC_MPLY, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,
  _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
