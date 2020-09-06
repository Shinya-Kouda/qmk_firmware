#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _RSFTL 1
#define _FUNCT 2
#define _SYMBL 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RSFTL,
  FUNCT,
  SYMBL,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   * |  Esc  |   q   |   w   |   e   |   r   |   t   |   (   |                      |   )   |   y   |   u   |   i   |   o   |   p   |  -    |
   * |-------+-------+-------+-------+-------+-------+-------+----------------------+-------+-------+-------+-------+-------+-------+-------|
   * | Tab   |   a   |   s   |   d   |   f   |   g   |   [   |                      |   ]   |   h   |   j   |   k   |   l   |   ;   |  '    |
   * |-------+-------+-------+-------+-------+-------+------------------------------+-------+-------+-------+-------+-------+-------+-------|
   * | LCtrl |   z   |   x   |   c   |   v   |   b   |       |Delete |      |RCtrl  |       |   n   |   m   |   ,   |   .   |   /   |  \    |
   * |---------------+-------+-------+-------+-------+ Space +-------+------+-------+ Enter +-------+-------+-------+-------+-------+-------|
   * | LShift|  GUI  | LAlt  |||||||||       | FUNCT |       | Bksp  ||||||||RShiftL|       | SYMBL | RAlt  ||||||||| Pscr  |       |  =    |
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
      KC_ESC ,  KC_Q ,   KC_W,   KC_E,   KC_R,   KC_T,KC_LPRN,                       KC_RPRN, KC_Y  ,   KC_U,   KC_I,   KC_O,   KC_P,KC_MINS, \
      KC_TAB ,  KC_A ,   KC_S,   KC_D,   KC_F,   KC_G,KC_LBRC,                       KC_RBRC, KC_H  ,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT, \
      KC_LCTL, KC_Z  ,   KC_X,   KC_C,   KC_V,   KC_B,        KC_DEL ,       KC_RCTL,         KC_N  ,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, \
      KC_LSFT,KC_LGUI,KC_LALT,        XXXXXXX, FUNCT ,KC_SPC ,KC_BSPC,       RSFTL  ,KC_ENT , SYMBL ,KC_RALT,        KC_PSCR,XXXXXXX, KC_EQL  \
  ),

  /* RSFTL
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   * |  Esc  |   Q   |   W   |   E   |   R   |   T   |   <   |                      |   >   |   Y   |   U   |   I   |   O   |   P   |   _   |
   * |-------+-------+-------+-------+-------+-------+-------+----------------------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   S   |   D   |   F   |   G   |   {   |                      |   }   |   H   |   J   |   K   |   L   |   :   |   "   |
   * |-------+-------+-------+-------+-------+-------+------------------------------+-------+-------+-------+-------+-------+-------+-------|
   * | LCtrl |   Z   |   X   |   C   |   V   |   B   |       |Delete |      | RCtrl |       |   N   |   M   |   @   |   !   |   ?   |   |   |
   * |---------------+-------+-------+-------+-------+       +-------+------+-------+ Enter +-------+-------+-------+-------+---------------|
   * | LShift|       | LAlt  |||||||||       |       |       | Bksp  ||||||||RShift |       |       | RAlt  |||||||||       |       |   +   |
   * ,---------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_RSFTL] = LAYOUT( \
      KC_ESC ,S(KC_Q),S(KC_W),S(KC_E),S(KC_R),S(KC_T),KC_LABK,                       KC_RABK,S(KC_Y),S(KC_U),S(KC_I),S(KC_O),S(KC_P),KC_UNDS, \
      KC_TAB ,S(KC_A),S(KC_S),S(KC_D),S(KC_F),S(KC_G),KC_LCBR,                       KC_RCBR,S(KC_H),S(KC_J),S(KC_K),S(KC_L),KC_COLN,KC_DQUO, \
      KC_LCTL,S(KC_Z),S(KC_X),S(KC_C),S(KC_V),S(KC_B),        KC_DEL ,       KC_RCTL,        S(KC_N),S(KC_M),  KC_AT,KC_EXLM,KC_QUES,KC_PIPE, \
      KC_LSFT,XXXXXXX,KC_LALT,        XXXXXXX,XXXXXXX,XXXXXXX,KC_BSPC,       KC_RSFT,KC_ENT ,XXXXXXX,KC_RALT,        XXXXXXX,XXXXXXX,KC_PLUS  \
  ),

  /* FUNCT
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F11  |                      |  F12  |  F6   |  F7   |  F8   |  F9   |  F10  |       |
   * |-------+-------+-------+-------+-------+-------+-------+----------------------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   1   |   2   |   3   |   4   |   5   |       |                      |       | Left  | Down  |  Up   | Right |       |       |
   * |-------+-------+-------+-------+-------+-------+------------------------------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   6   |   7   |   8   |   9   |   0   |       |       |      | RCtrl |       | Home  | PgDn  | PgUp  |  End  |       |       |
   * |---------------+-------+-------+-------+-------+       +-------+------+-------+       +-------+-------+-------+-------+---------------|
   * |       |       |       |||||||||       | FUNCT |       |       |||||||| RShift|       |       | RAlt  |||||||||       |       |       |
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_FUNCT] = LAYOUT( \
      XXXXXXX, KC_F1 ,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F11,                        KC_F12, KC_F6 ,  KC_F7,  KC_F8,  KC_F9, KC_F10,XXXXXXX, \
      XXXXXXX,KC_1   ,   KC_2,   KC_3,   KC_4,   KC_5,XXXXXXX,                       XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,XXXXXXX, \
      XXXXXXX,KC_6   ,   KC_7,   KC_8,   KC_9,   KC_0,        XXXXXXX,       KC_RCTL,        KC_HOME,KC_PGDN,KC_PGUP,KC_END ,XXXXXXX,XXXXXXX, \
      XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,  FUNCT,XXXXXXX,XXXXXXX,       KC_RSFT,XXXXXXX,XXXXXXX,KC_RALT,        XXXXXXX,XXXXXXX,XXXXXXX  \
  ),

  /* SYMBL
   * ,--------------------------------------------------------------------------------------------------------------------------------------.
   * |       |       |       |       |       |   ~   |       |                      |       |       |       |       |       |   %   |       |
   * |-------+-------+-------+-------+-------+-------+-------+----------------------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   *   |   #   |   $   |       |       |       |                      |       |   ^   |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+------------------------------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |   `   |       |       |      |       |       |   &   |       |       |       |       |       |
   * |---------------+-------+-------+-------+-------+       +-------+------+-------+       +-------+-------+-------+-------+---------------|
   * |       |       |       |||||||||       |       |       |       ||||||||       |       | SYMBL |       |||||||||       |       |       |
   * ,---------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMBL] = LAYOUT( \
      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_TILD,XXXXXXX,                       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PERC,XXXXXXX, \
      XXXXXXX,KC_ASTR,KC_HASH, KC_DLR,XXXXXXX,XXXXXXX,XXXXXXX,                       XXXXXXX,KC_CIRC,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_GRV,        XXXXXXX,       XXXXXXX,        KC_AMPR,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
      XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,  SYMBL,XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RSFTL:
      if (record->event.pressed) {
        layer_on(_RSFTL);
        /*update_tri_layer(_RSFTL, _NUMBR, _FUNCT);*/
        register_code(KC_RSFT);
      } else {
        layer_off(_RSFTL);
        /*update_tri_layer(_RSFTL, _NUMBR, _FUNCT);*/
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
        /*update_tri_layer(_RSFTL, _NUMBR, _FUNCT);*/
      } else {
        layer_off(_FUNCT);
        /*update_tri_layer(_RSFTL, _NUMBR, _FUNCT);*/
      }
      return false;
      break;
    case SYMBL:
      if (record->event.pressed) {
        layer_on(_SYMBL);
        /*update_tri_layer(_RSFTL, _SYMBL, _FUNCT);*/
      } else {
        layer_off(_SYMBL);
        /*update_tri_layer(_RSFTL, _SYMBL, _FUNCT);*/
      }
      return false;
      break;
  }
  return true;
}
