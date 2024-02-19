#include "topsecret.h"

#ifndef WOATCUSTOMS_H
#define WOATCUSTOMS_H

//Macro declarations
enum custom_keycodes {
  WORD = SAFE_RANGE,
  TEAMSMUTE,
  SELWORD,
  UNAME,
};

//Macro cases
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
      case WORD:
        if (record->event.pressed) {
          SEND_STRING(_MYPWD);
        }
        break;

      case UNAME:
        if (record->event.pressed) {
          SEND_STRING(_MYUSERNAME);
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

#endif
