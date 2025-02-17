/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "features/socd_cleaner.h"
#include "color.h"

////////////////////////////////////////////////////////////////
// socd cleaning
////////////////////////////////////////////////////////////////
enum custom_keycodes {
    SOCDTOG = SAFE_RANGE,
    VOLMACRO,
    NKROTOG,
    CAPSTOG
};

socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_FN2,
    WIN_OVERRIDE,
    WIN_OVERRIDE2,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_RCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, MO(MAC_FN), KC_ROPTN, KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     _______,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        CAPSTOG,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NKROTOG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,         VOLMACRO,    KC_PSCR,  KC_CTANA, RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,         KC_BSPC,     KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,        KC_BSLS,     KC_DEL,   KC_END,   KC_PGDN,
        KC_RCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                  KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                  KC_RSFT,               KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN),  MO(WIN_FN2), KC_RCTL,     KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        XXXXXXX,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,    XXXXXXX,  XXXXXXX,  RGB_TOG,
        XXXXXXX,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,
        CAPSTOG,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BAT_LVL,  NKROTOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,              XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  MO(WIN_FN),  MO(WIN_FN2),    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX),

    [WIN_FN2] = LAYOUT_tkl_ansi(
        XXXXXXX,  DM_REC1,  DM_REC2,  XXXXXXX,  DM_RSTP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(WIN_BASE),  XXXXXXX,  TO(WIN_OVERRIDE),  TO(WIN_OVERRIDE2),    _______,    XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  DM_PLY1,  DM_PLY2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,
        CAPSTOG,  XXXXXXX,  SOCDTOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,              XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  MO(WIN_FN),  MO(WIN_FN2),    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX),

    [WIN_OVERRIDE] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  MO(WIN_FN),  MO(WIN_FN2),    _______,    _______,  _______,  _______),

    [WIN_OVERRIDE2] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  MO(WIN_FN),  MO(WIN_FN2),    _______,    _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN2]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_OVERRIDE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_OVERRIDE2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE

uint8_t on_hue = 85;
uint8_t off_hue = 0;

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // socd cleaning
    if (!process_socd_cleaner(keycode, record, &socd_v)) { return false; }
    if (!process_socd_cleaner(keycode, record, &socd_h)) { return false; }

    // toggles that cause the rgb to change to indicate their status are all
    // mapped on an fn layer so when the fn key is released, the rgb is overwritten again.
    switch (keycode) {
        case SOCDTOG:
            if (record->event.pressed) {
                HSV prev_hsv = rgb_matrix_get_hsv();
                socd_cleaner_enabled = !socd_cleaner_enabled;

                if (socd_cleaner_enabled) { 
                    rgb_matrix_sethsv_noeeprom(on_hue, prev_hsv.s, prev_hsv.v);
                } else {
                    rgb_matrix_sethsv_noeeprom(off_hue, prev_hsv.s, prev_hsv.v);
                }

                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case VOLMACRO:
            if (record->event.pressed) {
                // volume down 50 times to mute
                for (uint8_t i = 0; i < 50; i++) {
                    tap_code(KC_VOLD);
                }
                // volume up 6 times = 12 volume
                for (uint8_t i = 0; i < 6; i++) {
                    tap_code(KC_VOLU);
                }
            }
            return false;
        case NKROTOG:
            if (record->event.pressed) {
                HSV prev_hsv = rgb_matrix_get_hsv();
                keymap_config.nkro = !keymap_config.nkro;

                if (keymap_config.nkro) { 
                    rgb_matrix_sethsv_noeeprom(on_hue, prev_hsv.s, prev_hsv.v);
                } else {
                    rgb_matrix_sethsv_noeeprom(off_hue, prev_hsv.s, prev_hsv.v);
                }

                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case CAPSTOG:
            if (record->event.pressed) {
                HSV prev_hsv = rgb_matrix_get_hsv();

                // we store the previous caps state then programatically invert it to get the new state.
                // this is done because tap_code may not immediately flip the caps state and thus the
                // following if statement may receive incorrect information and show the wrong color
                bool prev_caps_state = host_keyboard_led_state().caps_lock;
                tap_code(KC_CAPS);

                if (!prev_caps_state) { 
                    rgb_matrix_sethsv_noeeprom(on_hue, prev_hsv.s, prev_hsv.v);
                } else {
                    rgb_matrix_sethsv_noeeprom(off_hue, prev_hsv.s, prev_hsv.v);
                }

                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
    }

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////
// change lighting mode to indicate a macro is being recorded
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// change rgb mode based on current layer (used for override layers)
// and when a macro is being recorded
////////////////////////////////////////////////////////////////////
uint8_t base_mode = 0;
uint8_t base_spd = 0;

const uint8_t override1_mode = RGB_MATRIX_CYCLE_PINWHEEL;
const uint8_t override1_spd = 25;
const uint8_t override2_mode = RGB_MATRIX_CYCLE_SPIRAL;
const uint8_t override2_spd = 30;
const uint8_t macro_mode = RGB_MATRIX_CYCLE_ALL;
const uint8_t macro_spd = 75;

bool recording_macro = false;

// pull mode and speed on keyboard boot to get base values.
// this means that if the default rgb is ever changed in
// via, then a keyboard reboot will let that mode be the base mode
// rather than needing to edit and reflash firmware
void keyboard_post_init_user(void) {
    base_mode = rgb_matrix_get_mode();
    base_spd = rgb_matrix_get_speed();
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // dont change rgb while recording macro and switching layers.
    // specifically for case where fn2 must be held to switch to
    // a different layer where the record macro button is
    // but then letting go of fn2 switches back to base layer
    // which would cause the rgb change triggered by recording macro
    // to immediately be overwritten
    if (recording_macro) return state;

    // set rgb mode based on highest active layer.
    // override layers are configured higher than fn layers so
    // they will take precedence.
    // use noeeprom because these are temporary effects
    // so theres no need to update the saved values
    switch (get_highest_layer(state)) {
        case WIN_OVERRIDE:
            rgb_matrix_mode_noeeprom(override1_mode);
            rgb_matrix_set_speed_noeeprom(override1_spd);
            break;
        case WIN_OVERRIDE2:
            rgb_matrix_mode_noeeprom(override2_mode);
            rgb_matrix_set_speed_noeeprom(override2_spd);
            break;
        default:
            // using noeeprom here also prevents new rgb settings from being 
            // overwritten with the original rgb settings if you forget to reboot
            // then use an override layer
            rgb_matrix_mode_noeeprom(base_mode);
            rgb_matrix_set_speed_noeeprom(base_spd);
    }
    return state;
}

// change rgb while recording macro
void dynamic_macro_record_start_user(int8_t direction)
{
    rgb_matrix_mode_noeeprom(macro_mode);
    rgb_matrix_set_speed_noeeprom(macro_spd);

    recording_macro = true;
}

void dynamic_macro_record_end_user(int8_t direction)
{
    // return to base because macro recording can only be done on the default (base) layer
    // (for some reason)
    rgb_matrix_mode_noeeprom(base_mode);
    rgb_matrix_set_speed_noeeprom(base_spd);

    recording_macro = false;
}
