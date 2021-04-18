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
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    TTV,  // twitch tv keys
};

enum custom_keycodes {
    TWITCHTV = SAFE_RANGE,
    CHAT_MASHER,
    CHAT_LUV,
    CHAT_POGGERS,
    NEXT,
    LIST,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TWITCHTV:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("https://twitch.tv/jlbanger");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case CHAT_MASHER:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("jlbangMasher jlbangMasher jlbangMasher");
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case CHAT_LUV:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("jlbangLuv jlbangLuv jlbangLuv");
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case CHAT_POGGERS:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("jlbangPoggers jlbangPoggers jlbangPoggers");
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case NEXT:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("!next");
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case LIST:
            if (record->event.pressed) {
                // when keycode TWITCHTV is pressed
                SEND_STRING("!list");
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
    }
    return true;
};

    // DEFAULT DEFAULT layer
    // [BASE] = LAYOUT_moonlander(
    //     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //     KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
    //     KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    // LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
    //                                         KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    // ),

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   _______,          _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_HYPR,          KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
        KC_GRV,   _______, _______, KC_LALT, KC_LGUI,          OSL(TTV),         OSL(TTV),         KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, _______,
                                    LT(SYMB, KC_ENT), _______, _______,                   KC_ENT,  _______, LT(MDIA, KC_SPC)
    ),

    [SYMB] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             _______, KC_1,    KC_2,    KC_3,    _______, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_TOG,           RGB_TOG,          KC_0,    KC_DOT,  _______, _______,  _______,
                                            _______, _______, _______,           TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           LCTL(KC_A), _______, _______, _______, _______,  _______, RESET,
        _______, _______, _______, _______, _______, _______, _______,           LCTL(KC_V), _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                                _______, KC_LBRC, KC_RBRC, _______,  _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,             KC_VOLU, KC_VOLD, KC_MUTE,  _______, _______,
                                            _______, _______, _______,           _______,    _______, KC_MPLY
    ),

    [TTV] = LAYOUT_moonlander(
        TWITCHTV, _______, _______, _______, _______, _______, _______,          _______, _______, _______,     _______, _______,  _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______, _______, _______,     _______, _______,  CHAT_POGGERS, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______, _______, _______,     _______, CHAT_LUV, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, CHAT_MASHER, _______, _______,  _______, LIST,
        _______,  _______, _______, _______, _______,         _______,           _______,          _______,     _______, _______,  _______, NEXT,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

uint32_t default_layer_state_set_user(uint32_t state) {
  rgblight_sethsv(HSV_PURPLE);
  rgblight_mode(5);
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch(layer) {
    case BASE:
        rgblight_sethsv(HSV_PURPLE);
        break;
    case SYMB:
        rgblight_sethsv(HSV_WHITE);
        break;
    case MDIA:
        rgblight_sethsv(HSV_GREEN);
        break;
    case TTV:
        rgblight_sethsv(HSV_CYAN);
        break;
    }
    return state;
}
