#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
// disable recursive macro recording
#define DYNAMIC_MACRO_NO_NESTING

// default rgb settings upon flashing, not upon each boot
// https://docs.qmk.fm/features/rgb_matrix
#define RGB_MATRIX_DEFAULT_HUE 200 // rgb(180,0,255) = 282 deg hue. then convert from 0-360 range to 0-255 range gives 199.75 hue value
#define RGB_MATRIX_DEFAULT_SPD 60
#define RGB_MATRIX_DEFAULT_VAL 110
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
