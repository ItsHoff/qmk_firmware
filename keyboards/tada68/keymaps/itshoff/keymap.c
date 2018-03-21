#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _CL 1
#define _FL 2

#define _______ KC_TRNS
#define AGUI(kc) LALT(LGUI(kc))

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
    INPUT_DEFAULT,
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
   * |FN(Esc)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |F11 |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RsCaps| Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_F5, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  LT(_CL, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, KC_ENT,KC_F11,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,TD(TD_RSHIFT_CAPS),KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _CL: Caps Layer (rest Alt + GUI modified)
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |Lft|Dwn|Up|Rght|   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_CL] = KEYMAP_ANSI(
  AGUI(KC_GRV), KC_F1 ,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,         KC_F9,        KC_F10,        KC_F11,  KC_F12,        KC_DEL,        AGUI(KC_ESC),  \
  AGUI(KC_TAB), AGUI(KC_Q), AGUI(KC_W), AGUI(KC_E), AGUI(KC_R), AGUI(KC_T), AGUI(KC_Y), AGUI(KC_U), AGUI(KC_I),    AGUI(KC_O),   AGUI(KC_P),    AGUI(KC_LBRC), AGUI(KC_RBRC), AGUI(KC_BSLS), AGUI(KC_DEL),  \
  _______,      AGUI(KC_A), AGUI(KC_S), AGUI(KC_D), AGUI(KC_F), AGUI(KC_G), KC_LEFT,    KC_DOWN,    KC_UP,         KC_RIGHT,     AGUI(KC_SCLN), AGUI(KC_QUOT), AGUI(KC_ENT),           AGUI(KC_PGUP), \
  _______,      AGUI(KC_Z), AGUI(KC_X), AGUI(KC_C), AGUI(KC_V), AGUI(KC_B), AGUI(KC_N), AGUI(KC_M), AGUI(KC_COMM), AGUI(KC_DOT), AGUI(KC_SLSH),          KC_BTN1,       KC_MS_U,       KC_BTN2,       \
  _______,_______,_______,                 AGUI(KC_SPC),                                            _______,       _______,      _______,                KC_MS_L,       KC_MS_D,       KC_MS_R),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   |F|WIN |MAC |LIN |   |   |   |   |   |MUT|VU-|VU+|Del   |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * | Esc  |<- |Dn | ->|   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |  |PREV|NEXT|PAUSE|McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______,_______,_______,_______,_______, _______, _______, _______, _______, _______, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  KC_ESC ,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,_______,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,KC_F24,KC_MS_L,KC_MS_D, KC_MS_R),
};

void my_tap(uint16_t keycode) {
    register_code(keycode);
    unregister_code(keycode);
};

// Use this macro instead of SEND_STRING because we require numpad keys
#define WIN_ALT_CODE(a, b, c, d) { \
    register_code(KC_LALT);        \
    my_tap(KC_KP_##a);             \
    my_tap(KC_KP_##b);             \
    my_tap(KC_KP_##c);             \
    my_tap(KC_KP_##d);             \
    unregister_code(KC_LALT);      \
    }
