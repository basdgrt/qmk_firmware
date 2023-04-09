#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _INTELLIJ,
};

#define LSFT_KA LSFT_T(KC_A)
#define LCTL_KS LCTL_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LALT_KF LALT_T(KC_F)
#define LALT_KJ LALT_T(KC_J)
#define RGUI_KK RGUI_T(KC_K)
#define RCTL_KL RCTL_T(KC_L)
#define RS_SCLN RSFT_T(KC_SCLN)

#define LCTL_KR LCTL_T(KC_R)
#define LGUI_KS LGUI_T(KC_S)
#define LALT_KT LALT_T(KC_T)
#define LALT_KN LALT_T(KC_N)
#define RGUI_KE RGUI_T(KC_E)
#define RCTL_KI RCTL_T(KC_I)
#define RSFT_KO RSFT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, LSFT_KA, LCTL_KS, LGUI_KD, LALT_KF,    KC_G,                         KC_H, LALT_KJ, RGUI_KK, RCTL_KL, RS_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_INTELLIJ), MO(_LOWER), KC_ENT,   KC_SPC, TG(_RAISE), _______
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC,  KC_EQL, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_TRNS, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, _______,  _______, _______, _______, _______,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_DEL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_TRNS, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_INTELLIJ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,  _______,  _______,  KC_F7,   KC_F8,   KC_F9,                        KC_F9,   KC_F8,   KC_F7, _______,  _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, LCTL(KC_D), LCTL(KC_R), _______,               _______, LALT(KC_F12), LGUI(KC_1), _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// TODO do we really need this? Or can i just use MO(LAYER)?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#ifdef OLED_ENABLE
 
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180; 
}

bool oled_task_user() {
    oled_set_cursor(0, 1);

  if (is_keyboard_master()) {
      switch (get_highest_layer(layer_state)) {
          case _QWERTY :
              oled_clear();
              oled_write("Main", false);
              break;
          case _LOWER :
              oled_clear();
              oled_write("Numbers", false);
              break;
          case _RAISE : 
              oled_clear();
              oled_write("Navigation", false);
              break;
          case _INTELLIJ :
              oled_clear();
              oled_write("IntelliJ", false);
              break;
      }
  }

    return false;
}

#endif
