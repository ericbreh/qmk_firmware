// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _RAISE,
};

enum custom_keycodes {
    KC_LSTRT = QK_USER,
    KC_LEND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,  KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,  KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS,
  KC_ESC,   KC_A,  KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,  KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
                   XXXXXXX,  XXXXXXX,  KC_LALT,  KC_LCTL,  KC_LGUI,  LT(_RAISE, KC_SPC), KC_RSFT,  KC_RCTL,  XXXXXXX, XXXXXXX
),

[_RAISE] = LAYOUT(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_BRID,  KC_BRIU,  KC_DEL,
  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                       KC_PGUP,  KC_MINS,   KC_EQL,   KC_LBRC,  KC_RBRC,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_CAPS,                      KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,  _______,  _______,  KC_PGDN,  KC_LSTRT,  XXXXXXX,  KC_LEND,  XXXXXXX,  _______,
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
