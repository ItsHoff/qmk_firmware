#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _CL 1
#define _FL 2

#define _______ KC_TRNS

enum custom_keycodes {
    MY_O = SAFE_RANGE,
    MY_A,
    MY_AO,
    MY_EUR,
    SET_INPUT_F,
    SET_INPUT_WIN,
    SET_INPUT_MAC,
    SET_INPUT_LIN,
};

enum tap_dance {
    TD_RSHIFT_CAPS = 0
};

enum input_method {
    INPUT_F,
    INPUT_WIN,
    INPUT_MAC,
    INPUT_LIN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSHIFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |F5  |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FN(Esc)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RsCaps| Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_F5, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  LT(_CL, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, KC_ENT,KC_PGUP,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,TD(TD_RSHIFT_CAPS),KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _CL: Caps Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up | € |   |   |   |   |   |   |   | å |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |Lft|Dwn|Up|Rght| ö | ä |   F13  |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_CL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP, MY_EUR,_______, _______,_______,_______,_______,_______,_______, MY_AO,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT, MY_O, MY_A,    KC_F13  , KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   |F|WIN |MAC |LIN |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______,SET_INPUT_F,SET_INPUT_WIN,SET_INPUT_MAC,SET_INPUT_LIN, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,KC_F24,KC_MS_L,KC_MS_D, KC_MS_R),
};

void my_tap(uint16_t keycode) {
    register_code(keycode);
    unregister_code(keycode);
};

#define WIN_ALT_CODE(a, b, c, d) { \
    register_code(KC_LALT);        \
    my_tap(KC_KP_##a);             \
    my_tap(KC_KP_##b);             \
    my_tap(KC_KP_##c);             \
    my_tap(KC_KP_##d);             \
    unregister_code(KC_LALT);      \
    }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static int input_method = INPUT_F;
    if (record->event.pressed) {
        switch(keycode) {
            case SET_INPUT_F:
                input_method = INPUT_F;
                return false;
            case SET_INPUT_WIN:
                input_method = INPUT_WIN;
                return false;
            case SET_INPUT_MAC:
                input_method = INPUT_MAC;
                return false;
            case SET_INPUT_LIN:
                input_method = INPUT_LIN;
                return false;
            case MY_O:
                switch(input_method) {
                    case INPUT_F:
                    case INPUT_LIN:
                    case INPUT_MAC:
                        SEND_STRING(SS_TAP(X_F14));
                        return false;
                    case INPUT_WIN:
                        if (keyboard_report->mods & MOD_BIT(KC_LSHIFT)) {
                            unregister_code(KC_LSHIFT);
                            WIN_ALT_CODE(0, 2, 1, 4);
                            register_code(KC_LSHIFT);
                        } else {
                            WIN_ALT_CODE(0, 2, 4, 6);
                        }
                        return false;
                }
            case MY_A:
                switch(input_method) {
                    case INPUT_F:
                    case INPUT_LIN:
                    case INPUT_MAC:
                        SEND_STRING(SS_TAP(X_F15));
                        return false;
                    case INPUT_WIN:
                        if (keyboard_report->mods & MOD_BIT(KC_LSHIFT)) {
                            unregister_code(KC_LSHIFT);
                            WIN_ALT_CODE(0, 1, 9, 6);
                            register_code(KC_LSHIFT);
                        } else {
                            WIN_ALT_CODE(0, 2, 2, 8);
                        }
                        return false;
                }
            case MY_AO:
                switch(input_method) {
                    case INPUT_F:
                    case INPUT_LIN:
                    case INPUT_MAC:
                        SEND_STRING(SS_TAP(X_F16));
                        return false;
                    case INPUT_WIN:
                        if (keyboard_report->mods & MOD_BIT(KC_LSHIFT)) {
                            unregister_code(KC_LSHIFT);
                            WIN_ALT_CODE(0, 1, 9, 7);
                            register_code(KC_LSHIFT);
                        } else {
                            WIN_ALT_CODE(0, 2, 2, 9);
                        }
                        return false;
                }
            case MY_EUR:
                switch(input_method) {
                    case INPUT_F:
                    case INPUT_LIN:
                    case INPUT_MAC:
                        SEND_STRING(SS_TAP(X_F17));
                        return false;
                    case INPUT_WIN:
                        WIN_ALT_CODE(0, 1, 2, 8);
                        return false;
                }
        }
    }
    return true;
};
