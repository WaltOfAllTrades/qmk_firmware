//This is the c configuration file for the keymap

#pragma once

// #define USE_I2C

/* Handedness settings */
#define MASTER_LEFT
// #define EE_HANDS

/* Auto Shift settings*/
#define AUTO_SHIFT_TIMEOUT 160

/* Caps Word settings*/
#define CAPS_WORD_IDLE_TIMEOUT 2500

/* Leader settings*/
//#define LEADER_KEY_STRICT_KEY_PROCESSING
//#define LEADER_NO_TIMEOUT //Disables initial timeout keeping per-key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

/* Tap Dance settings
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
 */

/* Ones Shot settings */
/* #define ONESHOT_TAP_TOGGLE 5, Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  // Time (in ms) before the one shot key is released

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* Feature disable options, useful to firmware size reduction.*/

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
