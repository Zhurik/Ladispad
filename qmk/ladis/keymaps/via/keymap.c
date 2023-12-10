
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BL] =   { ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN), ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN)  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [_BL] = LAYOUT(
		KC_Q, KC_W, KC_E,
		KC_A, KC_S, KC_D, KC_UP,
		KC_Z, KC_X, KC_C, KC_DOWN
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
			tap_code(KC_BRIGHTNESS_DOWN);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
		}
    }
    return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Hello, Vovan"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif

