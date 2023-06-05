// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "os_detection.h"

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  COPY,
  PASTE,
  CUT,
  UNDO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPLY,      KC_MPLY, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQUAL,
        KC_LSFT,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LBRC,      KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                     KC_LGUI, TG(2),   KC_LALT, KC_SPC,       KC_ENT,  KC_BSPC, TG(1),   KC_GRV
    ),
    [1] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_ESC,  KC_WH_U, KC_WBAK, KC_WFWD, KC_MS_U,                          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_ESC,
        _______, KC_LALT, KC_WH_D, KC_LSFT, KC_LCTL, KC_MS_D,                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_BSPC, KC_MENU,
        _______, UNDO,    CUT,     COPY,    PASTE,   KC_BTN1, _______,        _______, KC_BTN2, KC_BTN3, KC_MS_L, KC_MS_R, KC_WH_L, KC_WH_R,
                                   _______, _______, _______, _______,        _______, _______, _______, KC_DEL
    ),
    [2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        XXXXXXX, TG(0),   TG(4),   XXXXXXX, XXXXXXX, QK_BOOT, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_SAI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,RGB_SAD, RGB_M_P,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                          XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_VAI, RGB_M_B,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_VAD, RGB_M_R,
                                   _______, _______, _______, _______,        _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPLY,        KC_MPLY, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQUAL,
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,        KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                     KC_LGUI, TG(2),   KC_LALT, KC_SPC,         KC_ENT,  KC_BSPC, TG(1),   KC_GRV
        ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }

};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

bool is_mac(void) {
  switch (detected_host_os()) {
    case OS_MACOS:
    case OS_IOS:
      return true;
    default:
      return false;
  }
}

#define L_CONTROL(is_mac, kc) (is_mac ? LGUI(kc) : LCTL(kc))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
  case COPY:
    if (record->event.pressed) {
      tap_code16(L_CONTROL(is_mac(), KC_C));
      return false;
    }
  case PASTE:
    if (record->event.pressed) {
      tap_code16(L_CONTROL(is_mac(), KC_V));
      return false;
    }
  case CUT:
    if (record->event.pressed) {
      tap_code16(L_CONTROL(is_mac(), KC_X));
      return false;
    }
  case UNDO:
    if (record->event.pressed) {
      tap_code16(L_CONTROL(is_mac(), KC_Z));
      return false;
    }
    default:
      return true;
  }
}