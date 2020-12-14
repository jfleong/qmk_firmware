#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    KC_MEDIA_PLAY_PAUSE,        KC_ESC,  KC_F1,   KC_F2,   KC_F3,         KC_F4,    KC_F5,          KC_F6, KC_F7,    KC_F8,         KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
    LALT(KC_A),   LALT(KC_V),   KC_GRV,  KC_1,    KC_2,    KC_3,          KC_4,     KC_5,           KC_6,  KC_7,     KC_8,          KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    KC_F13,       KC_F16,       KC_TAB,  KC_Q,    KC_W,    KC_E,          KC_R,     KC_T,           KC_Y,  KC_U,     KC_I,          KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F17,       KC_F18,       KC_LCTL, KC_A,    KC_S,    KC_D,          KC_F,     KC_G,           KC_H,  KC_J,     KC_K,          KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_F19,       KC_F20,       KC_LSFT,          KC_Z,    KC_X,          KC_C,     KC_V,           KC_B,  KC_N,     KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    LSFT(KC_F23), LSFT(KC_F24), KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), _______,  KC_BSPC,               _______,  LT(1, KC_SPC), TG(2),   KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_SAI, RGB_SAD, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______,
    RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_0,    TG(2),   _______, _______, _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MEDIA_NEXT_TRACK);
        } else {
            tap_code(KC_MEDIA_PREV_TRACK);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
}
