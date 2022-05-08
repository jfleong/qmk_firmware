/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum layers {
    BASE = SAFE_RANGE,  // default layer
    LOWER,  // symbols
    RAISE,  // media keys
    ADJUST,  // twitch tv keys
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,             KC_7,       KC_8, KC_9,  KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   _______,          LALT(KC_A), KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   _______,          LALT(KC_V), KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                                 KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_GRV,   _______, _______, KC_LGUI, LOWER,            KC_LALT,          KC_RALT,          RAISE, _______, _______, _______, LSFT(KC_F22),
                                             KC_ENT,  KC_SPC,  _______,          _______,  KC_ENT, KC_SPC
    ),

    [_LOWER] = LAYOUT_moonlander(
        KC_GRV,  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, KC_ESC,  _______, _______, _______, _______, _______,           _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_0,    KC_DOT,  _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [_RAISE] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_LPRN, KC_RPRN, KC_PAST,  _______, _______,
        _______, _______, _______, KC_MINS, KC_EQL,  _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BSPC, _______,
        _______, _______, _______, _______, _______, _______,                             _______, KC_LBRC, KC_RBRC, KC_BSLS,  _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______,  _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
