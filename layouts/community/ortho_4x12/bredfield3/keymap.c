#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Keymap layers
enum layer_names {
    _BASE_LAYER,
    _LOWER_LAYER,
    _RAISE_LAYER,
    _NAVIGATION_LAYER,
    _UI_LAYER,
};

// Readability
#define ___X___ XXXXXXX

// Layer switches aliases
#define BSP_LOW  LT(_LOWER_LAYER, KC_BSPC)
#define DEL_RSE  LT(_RAISE_LAYER, KC_DEL)
#define UI_ESC   LT(_UI_LAYER, KC_ESC)
#define UI_TAB   LT(_UI_LAYER, KC_TAB)
#define SPC_NAV  LT(_NAVIGATION_LAYER, KC_SPACE)

// Mod taps
#define ENT_SFT  LSFT_T(KC_ENT)
// Home row mod taps
#define H_A      LGUI_T(KC_A)
#define H_S      LALT_T(KC_S)
#define H_D      LCTL_T(KC_D)
#define H_F      LSFT_T(KC_F)
#define H_G      LT(_LOWER_LAYER, KC_G)
#define H_H      LT(_RAISE_LAYER, KC_H)
#define H_J      LSFT_T(KC_J)
#define H_K      LCTL_T(KC_K)
#define H_L      LALT_T(KC_L)
#define H_QUOT   LGUI_T(KC_QUOTE)

// GUI
#define GUI_1    LGUI(KC_1)
#define GUI_2    LGUI(KC_2)
#define GUI_3    LGUI(KC_3)
#define GUI_4    LGUI(KC_4)
#define GUI_5    LGUI(KC_5)
#define GUI_6    LGUI(KC_6)
#define GUI_7    LGUI(KC_7)
#define GUI_8    LGUI(KC_8)
#define GUI_9    LGUI(KC_9)
#define GUI_0    LGUI(KC_0)
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
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ___X___, ___X___, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    H_A,     H_S,     H_D,      H_F,    H_G,     ___X___, ___X___, H_H,     H_J,     H_K,     H_L,     H_QUOT,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ___X___, ___X___, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ___X___, ___X___, ___X___, BSP_LOW, ENT_SFT, UI_ESC,  UI_TAB,  SPC_NAV, DEL_RSE, ___X___, ___X___, ___X___
// |-----------------------------------------------------------------------------------------------------------|
),

[_LOWER_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ___X___, ___X___, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,   ___X___, ___X___, KC_SCLN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    GUI_6,   GUI_7,   GUI_8,   GUI_9,   GUI_0,   ___X___, ___X___, KC_GRV,  KC_TILD, KC_BSLS, KC_PIPE, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// |-----------------------------------------------------------------------------------------------------------|
),

[_RAISE_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___X___, ___X___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___X___, ___X___, KC_COLN, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ___X___, ___X___, KC_TILD, KC_PIPE, ___X___, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// |-----------------------------------------------------------------------------------------------------------|
),

[_NAVIGATION_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_HOME, KC_UP,   KC_END,  ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_RGHT, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PGDN, ___X___, KC_PGUP, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// |-----------------------------------------------------------------------------------------------------------|
),

[_UI_LAYER] = LAYOUT_ortho_4x12(
// |-----------------------------------------------------------------------------------------------------------|
    GUI_TAB, KC_MUTE, KC_VOLU, KC_MPLY, ___X___, ___X___, ___X___, ___X___, KC_F14,  WIN_UP,  KC_F15,  ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    GUI_GRV, KC_MRWD, KC_VOLD, KC_MFFD, ___X___, ___X___, ___X___, ___X___, WIN_LEFT,WIN_DOWN,WIN_RGHT,___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    GUI_SSF, GUI_SST, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
// |-----------------------------------------------------------------------------------------------------------|
),
};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case ENT_SFT:
        return TAPPING_TERM - 50;
    default:
      return TAPPING_TERM;
  }
}