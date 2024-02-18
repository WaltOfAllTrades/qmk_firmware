/* ---- RFC ----

Mouse Jiggler - https://github.com/DIYCharles/MouseJiggler/blob/master/QMK%20firmware/mousejiggler/keymaps/default/keymap.c
OSL for one key macro layer
#include "features/sentence_case.h" // https://getreuer.info/posts/keyboards/sentence-case/index.html
#include "features/custom_shift_keys.h"// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_lock.md
TT(capsword) to shift to an all caps layer as a secondary caps key that avoids lintalist
Shift leader key
Tap dance for caps word and capslock
leader key for exact match SN url trim whitespace if needed
#LT(ent, control)
#LT(caps word, control)
#LT(tab, alt
#custom shift character: Normal / Shifted (only if auto shift works)
#	Shifted Tab via custom shifted key
# Comma/SCLN
#	LBRC / RBRC
#	LParanthesis / RParanthesis
#	LAnglebracket / Ranglebracket
#	L curly BRC / R curly BRC
#
#Tap Tap Hold on all puntuation such as Dot. T =(.) TT=(. ) Hold= Angle bracket
#Next sentence macro getreuer.info/posts/keyboards/macros/index.html#macros-that-respond-to-mods
*/

#include QMK_KEYBOARD_H

/*
// Tap Dance declarations
enum {
    TD_TAB_SHIFT,
};

// Tap Dance definitions

ACTION_TAP_DANCE_DOUBLE(kc1, kc2) 
  Tap => Tapped kc1, Tap Tap => Tapped kc2. Hold => Held kc1, Tap Hold => Held kc2
ACTION_TAP_DANCE_LAYER_MOVE(kc, layer)
  Sends the kc keycode when tapped once, or moves to layer (functions like the TO layer keycode).
ACTION_TAP_DANCE_LAYER_TOGGLE(kc, layer)
  Sends the kc keycode when tapped once, or toggles the state of layer (functions like the TG layer keycode).
ACTION_TAP_DANCE_FN(fn)
  Calls the specified function - defined in the user keymap - with the final tap count of the tap dance action.


tap_dance_action_t tap_dance_actions[] = {
    // Tap once for TAB, twice for SHIFTED TAB
    [TD_TAB_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, //LSHFT(TAB) KC_CAPS),
};
*/

//Combo 

enum combo_events {
  TRIPLE_CLICK_COPY,
  COPY,
  CLICK_PASTE,
  DOUBLE_CLICK_COPY,
  EXACT_MATCH_PASTE_ENTER,
  TRIPLE_CLICK,
  PASTE_COMBO,
};

const uint16_t PROGMEM triple_click_copy_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM click_paste_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM double_click_copy_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM exact_match_paste_enter_combo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM triple_click_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM paste_combo_combo[] = {KC_F, KC_V, COMBO_END};



combo_t key_combos[] = {
  [TRIPLE_CLICK_COPY] = COMBO_ACTION(triple_click_copy_combo),
  [COPY] = COMBO_ACTION(copy_combo),
  [CLICK_PASTE] = COMBO_ACTION(click_paste_combo),
  [DOUBLE_CLICK_COPY] = COMBO_ACTION(double_click_copy_combo),
  [EXACT_MATCH_PASTE_ENTER] = COMBO_ACTION(exact_match_paste_enter_combo),
  [TRIPLE_CLICK] = COMBO_ACTION(triple_click_combo),
  [PASTE_COMBO] = COMBO_ACTION(paste_combo_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case TRIPLE_CLICK_COPY:
      if (pressed) {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_C));
      }
      break;
    case COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case CLICK_PASTE:
      if (pressed) {
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_V));
      }
      break;
    case DOUBLE_CLICK_COPY:
      if (pressed) {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_C));
      }
      break;
    case EXACT_MATCH_PASTE_ENTER:
      if (pressed) {
        SEND_STRING("https://snhu.service-now.com/text_search_exact_match.do?sysparm_search=");
        tap_code16(LCTL(KC_V));
        tap_code16(KC_ENT);
      }
      break;
    case TRIPLE_CLICK:
      if (pressed) {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
      }
      break;
    case PASTE_COMBO:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
  }
}


//Macro declarations
enum custom_keycodes {
  WORD = SAFE_RANGE,
  TEAMSMUTE,
  SELWORD,
  UNAME,
};

//Define Keymap Aliases
#define _BASE 0
#define _DIRNUMFUNC 1
#define _LEFTNUM 2
#define _TRNSSPACED10 3

//Define Keycode Aliases
#define __X__ KC_NO
#define _______ KC_TRNS
#define LAY1_SPC LT(1, KC_SPC)
#define LAY2_MO MO(2)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    __X__     ,__X__     ,KC_F1     ,KC_F2     ,KC_F3     ,KC_F4     ,KC_F5     ,KC_F6     ,KC_F7     ,                    KC_F8     ,KC_F9     ,KC_F10    ,KC_F11    ,KC_F12    ,KC_F13    ,KC_F14    ,__X__     ,__X__     ,
    __X__     ,KC_GRV    ,KC_1      ,KC_2      ,KC_3      ,KC_4      ,KC_5      ,KC_6      ,KC_7      ,                    KC_8      ,KC_9      ,KC_0      ,KC_MINS   ,KC_EQL    ,KC_PSCR   ,KC_DEL    ,KC_BSPC   ,__X__     ,
    __X__     ,KC_TAB    ,KC_TAB    ,KC_Q      ,KC_W      ,KC_E      ,KC_R      ,KC_T      ,KC_LBRC   ,                    KC_RBRC   ,KC_Y      ,KC_U      ,KC_I      ,KC_O      ,KC_P      ,KC_LBRC   ,KC_RBRC   ,__X__     ,
    KC_AGAIN  ,CW_TOGG   ,CW_TOGG   ,KC_A      ,KC_S      ,KC_D      ,KC_F      ,KC_G      ,KC_LPRN   ,                    KC_RPRN   ,KC_H      ,KC_J      ,KC_K      ,KC_L      ,KC_QUOT   ,KC_SCLN   ,KC_ENT    ,__X__     ,
    KC_UNDO   ,KC_LSFT   ,KC_LSFT   ,KC_Z      ,KC_X      ,KC_C      ,KC_V      ,KC_B      ,__X__     ,                    __X__     ,KC_N      ,KC_M      ,KC_COMM   ,KC_DOT    ,KC_SLSH   ,KC_NUBS   ,KC_RSFT   ,__X__     ,
    QK_LEAD   ,KC_LCTL   ,KC_LCTL   ,KC_LALT   ,KC_LGUI   ,KC_LALT   ,LAY2_MO   ,LAY1_SPC  ,QK_LEAD   ,                    KC_UNDS   ,LAY1_SPC  ,KC_RALT   ,KC_RALT   ,__X__     ,KC_LEFT   ,KC_DOWN   ,KC_RIGHT  ,__X__
),

/* 
_BASE
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*|       |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |      |  F8   |  F9   |  F10  |  F11  |  F12  |  F13  |  F14  |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       | GRAVE |   1   |   2   |   3   |   4   |   5   |   6   |   7   |      |   8   |   9   |   0   |   -   |   =   |PRTSCRN|  DEL  | BKSPC |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |  TAB  |  TAB  |   Q   |   W   |   E   |   R   |   T   |   [   |      |   ]   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*| AGAIN |CAPWORD|CAPWORD|   A   |   S   |   D   |   F   |   G   |   (   |      |   )   |   H   |   J   |   K   |   L   |   '   |   ;   |  ENT  |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|  UNDO | SHIFT | SHIFT |   Z   |   X   |   C   |   V   |   B   |       |      |       |   N   |   M   |   ,   |   .   |   /   |   \   | SHIFT |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|  LEAD |  CTRL |  CTRL |  ALT  |  GUI  |  ALT  | MO(2) |SPC(L1)|  LEAD |      |   _   |SPC(L1)|  ALT  |  ALT  |       |  LEFT |  DWN  | RIGHT |       |
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*/


[_DIRNUMFUNC] = LAYOUT(
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,KC_ESC    ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,KC_SLASH  ,KC_ASTR   ,KC_MINUS  ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,KC_MS_BTN1,KC_UP     ,KC_MS_BTN2,_______   ,KC_MFFD   ,                    KC_VOLU   ,_______   ,KC_7      ,KC_8      ,KC_9      ,KC_PPLS   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,KC_CAPS   ,_______   ,KC_LEFT   ,KC_DOWN   ,KC_RIGHT  ,_______   ,KC_MRWD   ,                    KC_VOLD   ,_______   ,KC_4      ,KC_5      ,KC_6      ,KC_ENT    ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,KC_LBRC   ,_______   ,                    _______   ,_______   ,KC_1      ,KC_2      ,KC_3      ,_______   ,KC_UP     ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    KC_CALC   ,_______   ,KC_0      ,KC_COMM   ,KC_DOT    ,KC_LEFT   ,KC_DOWN   ,KC_RIGHT  ,_______
),

/* 
_DIRNUMFUNC
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*|       |       |       |       |       |       |       |       |       |      |       |       |       |       |       |       |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |  ESC  |       |       |       |       |       |       |       |      | VOL UP|       |       |   /   |   *   |   -   |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |       |       |       | L CLIK|  UP   | R CLIK|       |  FFWD |      |VOL DWN|       |   7   |   8   |   9   |   +   |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |       |  CAPS |       |  LEFT |  DWN  | RIGHT |       |  RWD  |      |       |       |   4   |   5   |   6   |  ENT  |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |       |       |       |       |       |       |       |       |      |       |       |   1   |   2   |   3   |       |   UP  |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |       |       |       |       |       |       |       |       |      |  CALC |       |   0   | COMMA |  DOT  |  LEFT |  DWN  | RIGHT |       |
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*/

[_LEFTNUM] = LAYOUT(
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,KC_ESC    ,_______   ,_______   ,_______   ,KC_SLASH  ,KC_ASTR   ,KC_MINUS  ,_______   ,                    AS_TOGG   ,_______   ,_______   ,KC_SLASH  ,KC_ASTR   ,KC_MINUS  ,_______   ,_______   ,_______   ,
    _______   ,UNAME     ,_______   ,_______   ,KC_7      ,KC_8      ,KC_9      ,KC_PPLS   ,UNAME     ,                    AS_UP     ,_______   ,KC_7      ,KC_8      ,KC_9      ,KC_PPLS   ,_______   ,_______   ,_______   ,
    _______   ,WORD      ,_______   ,_______   ,KC_4      ,KC_5      ,KC_6      ,KC_ENT    ,WORD      ,                    AS_DOWN   ,_______   ,KC_4      ,KC_5      ,KC_6      ,KC_ENT    ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,KC_1      ,KC_2      ,KC_3      ,_______   ,_______   ,                    AS_RPT    ,_______   ,KC_1      ,KC_2      ,KC_3      ,_______   ,KC_UP     ,_______   ,_______   ,
    QK_BOOT   ,_______   ,_______   ,KC_COMMA  ,KC_DOT    ,KC_0      ,_______   ,_______   ,_______   ,                    KC_NUM    ,_______   ,KC_0      ,KC_COMMA  ,KC_DOT    ,KC_LEFT   ,KC_DOWN   ,KC_RIGHT  ,_______
    ),

/* 
_LEFTNUM
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*|       |       |       |       |       |       |       |       |       |      |       |       |       |       |       |       |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |  ESC  |       |       |       |   /   |   *   |   -   |       |      |ASHFTSW|       |       |   /   |   *   |   -   |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       | UNAME |       |       |   7   |   8   |   9   |   +   | UNAME |      |ASHFTUP|       |   7   |   8   |   9   |   +   |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |  WORD |       |       |   4   |   5   |   6   |  ENT  |  WORD |      |ASHFTDW|       |   4   |   5   |   6   |  ENT  |       |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|       |       |       |       |   1   |   2   |   3   |       |       |      |ASHFTPR|       |   1   |   2   |   3   |       |   UP  |       |       |
*|-------+-------+-------+-------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------+-------+-------+-------|
*|  BOOT |       |       | COMMA |  DOT  |   0   |       |       |       |      | NUMPAD|       |   0   | COMMA |  DOT  |  LEFT |  DWN  | RIGHT |       |
* -----------------------------------------------------------------------        -----------------------------------------------------------------------
*/

[_TRNSSPACED10] = LAYOUT(
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,
    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,                    _______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______   ,_______
   ),

};

/* PH comment multi line*/


//Macro cases
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
      case WORD:
        if (record->event.pressed) {
          SEND_STRING("xxx");
        }
        break;

      case UNAME:
        if (record->event.pressed) {
          SEND_STRING("xxx");
        }
        break;

      case TEAMSMUTE:
        if (record->event.pressed) {
          SEND_STRING("TEAMMUTE");
        }
        break;

      case SELWORD:  // Selects the current word under the cursor. //Not in use currently
          if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
              // Mac users, change LCTL to LALT:
              // SEND_STRING(SS_LALT(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
              }
          break;
      }

    return true;

  };

//Leader code

void leader_start_user(void) {
    // Replace with function to do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_C)) {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_C));
    } else if (leader_sequence_two_keys(KC_C, KC_C)) {
        SEND_STRING("https://snhu.service-now.com/text_search_exact_match.do?sysparm_search=");
        tap_code16(LCTL(KC_V));
        tap_code16(KC_ENT);
    } else if (leader_sequence_two_keys(KC_T, KC_R)) {
        SEND_STRING("Thank you,");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}