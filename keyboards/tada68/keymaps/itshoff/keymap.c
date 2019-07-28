#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE_LAYER 0
#define GAME_LAYER 1
#define CAPS_LAYER 2
#define MEDIA_LAYER 3
#define UNICODE_LAYER 4

// Caps layer modifier
#define CLMD(kc) LALT(LCTL(kc))

enum unicode_names {
    LOWER_A,
    UPPER_A,
    LOWER_O,
    UPPER_O,
    UNI_E,
};

const uint32_t PROGMEM unicode_map[] = {
    [LOWER_A] = 0x00E4,
    [UPPER_A] = 0x00C4,
    [LOWER_O] = 0x00F6,
    [UPPER_O] = 0x00D6,
    [UNI_E]  = 0x20AC,
};

enum tap_dance {
    TD_RSHIFT_CAPS = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSHIFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer: the default layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |F5  |
   * |----------------------------------------------------------------|
   * |HPR(Tab)| Q| W|  E|  R|  T|  Y|  U|  I|  O|  P|  [| ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CL(Esc)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |F11 |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RsCaps| Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |UL |ML |Esc |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[BASE_LAYER] = LAYOUT_ansi(
  KC_GRV,          KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, KC_F5,   \
  ALL_T(KC_TAB),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, KC_DEL,  \
  LT(CAPS_LAYER, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, KC_ENT,          KC_F11,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,TD(TD_RSHIFT_CAPS),KC_UP, KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                         OSL(UNICODE_LAYER),MO(MEDIA_LAYER),KC_ESC, KC_LEFT, KC_DOWN,         KC_RGHT),

  /*  Game Layer: Block unwanted keys from base layer while gaming
   * ,----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * | Tab |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * | CL    |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   | FL|    |   |   |    |
   * `----------------------------------------------------------------'
   */
[GAME_LAYER] = LAYOUT_ansi(
  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  KC_TAB,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,_______,_______, \
  MO(CAPS_LAYER), _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,_______, _______,_______,  \
  _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,_______, _______,_______,_______,_______, \
  _______, _______,_______,                _______,                        _______, _______, _______, _______,_______,_______),

  /* Caps Layer: Convenience binds and rest of the keys modified by ctrl + alt
   * ,----------------------------------------------------------------.
   * |   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |    |
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
[CAPS_LAYER] = LAYOUT_ansi(
  CLMD(KC_GRV), KC_F1 ,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,         KC_F9,        KC_F10,        KC_F11,  KC_F12,        KC_DEL,        CLMD(KC_ESC),  \
  CLMD(KC_TAB), CLMD(KC_Q), CLMD(KC_W), CLMD(KC_E), CLMD(KC_R), CLMD(KC_T), CLMD(KC_Y), CLMD(KC_U), CLMD(KC_I),    CLMD(KC_O),   CLMD(KC_P),    CLMD(KC_LBRC), CLMD(KC_RBRC), CLMD(KC_BSLS), CLMD(KC_DEL),  \
  _______,      CLMD(KC_A), CLMD(KC_S), CLMD(KC_D), CLMD(KC_F), CLMD(KC_G), KC_LEFT,    KC_DOWN,    KC_UP,         KC_RIGHT,     CLMD(KC_SCLN), CLMD(KC_QUOT), CLMD(KC_ENT),           CLMD(KC_PGUP), \
  _______,      CLMD(KC_Z), CLMD(KC_X), CLMD(KC_C), CLMD(KC_V), CLMD(KC_B), CLMD(KC_N), CLMD(KC_M), CLMD(KC_COMM), CLMD(KC_DOT), CLMD(KC_SLSH),          KC_BTN1,       KC_MS_U,       KC_BTN2,       \
  _______,_______,_______,                 CLMD(KC_SPC),                                            _______,       _______,      _______,                KC_MS_L,       KC_MS_D,       KC_MS_R),

  /* Media Layer: Media keys and other random keys
   * ,----------------------------------------------------------------.
   * |   |KP1|KP2|KP3|KP4|KP5|KP6|KP7|KP8|KP9|KP0|VU-|VU+|Mute   |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |PrScn|Hme |
   * |----------------------------------------------------------------|
   * | Esc  |<- |Dn | ->|   |GL |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |  |PREV|NEXT|PAUSE|McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[MEDIA_LAYER] = LAYOUT_ansi(
  _______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, KC_PSCREEN, KC_HOME, \
  KC_ESC ,KC_LEFT,KC_DOWN,KC_RIGHT,_______,TG(GAME_LAYER),_______,_______,_______,_______,_______,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,_______,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,KC_F24,KC_MS_L,KC_MS_D, KC_MS_R),

  /*  Unicode Layer: Special characters missing from the standard layout
   * ,----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |Win| € |   |   |   |   |   | ö |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |       | ä |   |   |   |   |   |   |   |Lnx|   |   |       |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |Mac|   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[UNICODE_LAYER] = LAYOUT_ansi(
  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  _______, UC_M_WC,  X(UNI_E),   _______,   _______,   _______,   _______,   _______,   XP(LOWER_O, UPPER_O),  _______,  _______, _______,_______,_______, \
  _______, XP(LOWER_A, UPPER_A),   _______,   _______,   _______,   _______,   _______,   _______,   _______,   UC_M_LN,   _______,_______, _______,_______,  \
  _______,         _______,   _______,   _______,   _______,   _______,   _______,   UC_M_OS,   _______,_______, _______,_______,_______,_______, \
  _______, _______,_______,                _______,                        _______, _______, _______, _______, _______, _______),
};
