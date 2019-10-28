#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

// Keymap layers
enum layer_names {
    _BASE_LAYER,
    _LOWER_LAYER,
    _NAVIGATION_LAYER,
    _UI_LAYER,
};

// Layer switches aliases
#define L_LOWER MO(_LOWER_LAYER)
#define L_RAISE MO(_RAISE_LAYER)
#define L_UI MO(_UI_LAYER)
#define SCL_NAV LT(_NAVIGATION_LAYER, KC_SCLN)
#define RSFT_ENT KC_SFTENT
#define LSFT_ENT LSFT_T(KC_ENT)
#define ALT_ENT LALT_T(KC_ENT)
#define TAB_ALT LALT_T(KC_TAB)
#define CTRL_DEL LCTL_T(KC_DEL)
#define SHFT_BSP LSFT_T(KC_BSPC)
#define ALT_ENT LALT_T(KC_ENT)
#define DEL_LOW LT(_LOWER_LAYER, KC_DEL)
#define GUI_Z LGUI_T(KC_Z)

// GUI chords
#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define GUI_4 LGUI(KC_4)
#define GUI_5 LGUI(KC_5)
#define GUI_6 LGUI(KC_6)
#define GUI_7 LGUI(KC_7)
#define GUI_8 LGUI(KC_8)
#define GUI_9 LGUI(KC_9)
#define GUI_0 LGUI(KC_0)
#define GUI_MIN LGUI(KC_MINS)
#define GUI_EQL LGUI(KC_EQL)
#define GUI_LBR LGUI(KC_LBRC)
#define GUI_RBR LGUI(KC_RBRC)
#define GUI_ENT LGUI_T(KC_ENT)
#define GUI_ESC LGUI_T(KC_ESC)
#define UNDO LGUI(KC_Z)
#define REDO LGUI(LSFT(KC_Z))
#define GUI_TAB LGUI(KC_TAB) // application toggle
#define GUI_GRV LGUI(KC_GRV) // window toggle
#define GUI_SSF LGUI(LSFT(KC_3)) // Full screen shot
#define GUI_SST LGUI(LSFT(KC_4)) // Targetted screen shot

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------------------+                 +-----------------------------------------------------.
 * |  Tab   |    Q   |    W   |    E   |    R   |    T   |                 |    Y   |    U   |    I   |    O   |    P   |   -    |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------------------------|
 * | GUI/Esc|    A   |    S   |    D   |    F   |    G   |                 |    H   |    J   |    K   |    L   |  ;/nav |   "    |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------------------------|
 * | Sft/ent| GUI/Z  |    X   |    C   |    V   |    B   |                 |    N   |    M   |    ,   |    .   |    /   | Sft/ent|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |   UI   |    \   |   |    |  Alt   |  GUI   |Del/Low |Shft/Bsp| Space  | Alt/ent|  Ctrl  |    `   |   ~    |   +    |   =    |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
[_BASE_LAYER] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    GUI_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    SCL_NAV, KC_QUOT,
    LSFT_ENT,GUI_Z,   KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_ENT,
    L_UI,    KC_BSLS, KC_PIPE, KC_LALT, KC_LGUI, DEL_LOW, SHFT_BSP,KC_SPACE,ALT_ENT, KC_LCTRL,KC_GRV,  KC_TILD, KC_PLUS, KC_EQL
),


/* Lower
 * ,-----------------------------------------------------+                 +-----------------------------------------------------.
 * |        |    !   |    @   |    #   |    $   |    {   |                 |    }   |    7   |    8   |    9   |    ,   |        |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------|
 * |        |    %   |    ^   |    &   |    *   |    (   |                 |    )   |    4   |    5   |    6   |    .   |        |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |    [   |                 |    ]   |    1   |    2   |    3   |    0   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
[_LOWER_LAYER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR,                   KC_RCBR, KC_7,    KC_8,    KC_9,    KC_COMM, _______,
    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,                   KC_RPRN, KC_4,    KC_5,    KC_6,    KC_DOT,  _______,
    _______, _______, _______, _______, _______, KC_LBRC,                   KC_RBRC, KC_1,    KC_2,    KC_3,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Navigation
 * ,-----------------------------------------------------+                 +-----------------------------------+--------+--------.
 * |        |        |        |        |        |        |                 |        |  Home  |   Up   |  End   |        |        |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                 |        |  Left  |  Down  | Right  |        |        |
 * |--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                 |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
[_NAVIGATION_LAYER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* UI
 * ,------------------------------------------------------                 |--------------------------+--------+-----------------.
 * | GUI Tab|        |        |        |        |        |                 |        |        |        | GUI -  | GUI =  |        |
 * |--------+--------+--------+--------+--------+---------                 |--------+--------+--------+--------+--------+--------|
 * | GUI `  |   F1   |    F2  |    F3  |    F4  |   F5   |                 |   F6   |   F7   |   F8   | GUI [  | GUI ]  |        |
 * |--------+--------+--------+--------+--------+---------                 |--------+--------+--------------------------+--------|
 * |        |Full SS | Area SS|        |        |        |                 |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------+--------+--------|
 * |        |  Prev  |  Play  | Next   |        |  Mute  |  Vol - |  Vol + |  Mute  |        |        |        |        | RESET  |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
[_UI_LAYER] = LAYOUT(
    GUI_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, GUI_MIN, GUI_EQL, XXXXXXX,
    GUI_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   GUI_LBR, GUI_RBR, XXXXXXX,
    _______, GUI_SSF, GUI_SST, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, RESET
),
};


uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case DEL_LOW:
      return TAPPING_TERM - 50;
    default:
      return TAPPING_TERM;
  }
}