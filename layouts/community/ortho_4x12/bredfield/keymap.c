#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Keymap layers
enum layer_names {
    _BASE_LAYER,
    _LOWER_LAYER,
    _NAVIGATION_LAYER,
    _UI_LAYER,
};

// Readability
#define ___X___ XXXXXXX

// Layer switches aliases
#define L_LOWER  MO(_LOWER_LAYER)
#define L_RAISE  MO(_RAISE_LAYER)
#define L_UI     MO(_UI_LAYER)
#define SCL_NAV  LT(_NAVIGATION_LAYER, KC_SCLN)
#define BSP_LOW  LT(_LOWER_LAYER, KC_BSPC)
#define DEL_UI LT(_UI_LAYER, KC_DEL)

// Mod taps
#define GUI_ESC  LGUI_T(KC_ESC)
#define RSFT_ENT KC_SFTENT
#define LSFT_ENT LSFT_T(KC_ENT)
#define TAB_ALT  LALT_T(KC_TAB)
#define ENT_SFT  LSFT_T(KC_ENT)
#define TAB_CTL  LCTL_T(KC_TAB)
#define MINS_SFT LSFT_T(KC_MINS)
#define UNDS_SFT LSFT_T(KC_UNDS)

// GUI
#define GUI_1    LGUI(KC_1)
#define GUI_2    LGUI(KC_2)
#define GUI_3    LGUI(KC_3)
#define GUI_4    LGUI(KC_4)
#define GUI_5    LGUI(KC_5)
#define GUI_6    LGUI(KC_6)
#define GUI_MIN  LGUI(KC_MINS)
#define GUI_EQL  LGUI(KC_EQL)
#define GUI_LBR  LGUI(KC_LBRC)
#define GUI_RBR  LGUI(KC_RBRC)
#define GUI_TAB  LGUI(KC_TAB)
#define GUI_GRV  LGUI(KC_GRV)
#define GUI_SSF  SGUI(KC_3) // Full screen shot
#define GUI_SST  SGUI(KC_4) // Targetted screen shot
#define WIN_UP   LCAG(KC_UP)
#define WIN_DOWN LCAG(KC_DOWN)
#define WIN_LEFT LCAG(KC_LEFT)
#define WIN_RGHT LCAG(KC_RIGHT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_BASE_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    TAB_ALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    GUI_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SCL_NAV, KC_QUOT,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_UNDS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MINS_SFT,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    DEL_UI,  ___X___, ___X___, KC_LGUI, BSP_LOW, ENT_SFT ,KC_SPACE,TAB_CTL, KC_RALT, ___X___, ___X___,  DEL_UI
// |-----------------------------------------------------------------------------------------------------------|
),


[_LOWER_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, KC_BSLS, KC_PIPE, KC_GRV,  KC_TILD, KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_COLN, _______, _______
// |-----------------------------------------------------------------------------------------------------------|
),

[_NAVIGATION_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_HOME, KC_UP,   KC_END,  ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_RGHT, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PGDN, ___X___, KC_PGUP, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// |-----------------------------------------------------------------------------------------------------------|
),

[_UI_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   GUI_LBR, WIN_UP,  GUI_RBR, GUI_MIN, GUI_EQL,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,   GUI_6,   WIN_LEFT,WIN_DOWN,WIN_RGHT,GUI_TAB, GUI_GRV,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_CAPS, GUI_SSF, GUI_SST, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_CAPS,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_MUTE, KC_MUTE, KC_VOLU, KC_F14,  KC_F15,  _______, RESET
// |-----------------------------------------------------------------------------------------------------------|
),
};


uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case BSP_LOW:
      return TAPPING_TERM - 50;
    default:
      return TAPPING_TERM;
  }
}