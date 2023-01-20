#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 11

/* key matrix pins */
#define DIRECT_PINS { { D3, B1, D4, C6, D7, E6, B4, B5, F4, F7, B3 } }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 1
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#ifdef RGB_DI_PIN
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif

#define ENCODERS_PAD_A { F5, B6 }
#define ENCODERS_PAD_B { F6, B2 }