#include QMK_KEYBOARD_H

enum custom_keycodes {
    TWITCHTV = SAFE_RANGE,
    CHAT_MASHER,
    CHAT_LUV,
    CHAT_POGGERS,
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
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    KC_MEDIA_PLAY_PAUSE,        KC_ESC,  KC_F1,   KC_F2,   KC_F3,         KC_F4,    KC_F5,  KC_F6, TG(3),    KC_F8,         KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
    LALT(KC_A),   LALT(KC_V),   KC_GRV,  KC_1,    KC_2,    KC_3,          KC_4,     KC_5,   KC_6,  KC_7,     KC_8,          KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    KC_F13,       KC_F16,       KC_TAB,  KC_Q,    KC_W,    KC_E,          KC_R,     KC_T,   KC_Y,  KC_U,     KC_I,          KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F17,       KC_F18,       KC_LCTL, KC_A,    KC_S,    KC_D,          KC_F,     KC_G,   KC_H,  KC_J,     KC_K,          KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_F19,       KC_F20,       KC_LSFT,          KC_Z,    KC_X,          KC_C,     KC_V,   KC_B,  KC_N,     KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    LSFT(KC_F23), LSFT(KC_F24), KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), _______,  KC_ENT,        _______,  LT(1, KC_SPC), OSL(4),  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* hold space to activate this layer */
  [1] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_SAI, RGB_SAD, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______,
    RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______,
    _______, _______, LT(2, KC_LSFT),   _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* hold space + Lshift to activate this layer */
  [2] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* F7 toggle to activate this layer */
  [3] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_0,    _______, _______, _______, _______, _______, _______
  ),
  /* right alt toggles this layer on */
  [4] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______,  _______, _______,     _______,  _______,      _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,     _______,  _______,      _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, TWITCHTV, _______, _______,     _______,  CHAT_POGGERS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,     CHAT_LUV, _______,      _______,         _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______,  _______, CHAT_MASHER, _______,  _______,      _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,     _______,  _______,      _______, _______, _______, _______
  ),
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
