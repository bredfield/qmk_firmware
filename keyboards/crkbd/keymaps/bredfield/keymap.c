#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

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
#define L_UI     MO(_UI_LAYER)
#define BSP_LOW  LT(_LOWER_LAYER, KC_BSPC)
#define DEL_RSE  LT(_RAISE_LAYER, KC_DEL)

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

#define H_A      LGUI_T(KC_A)
#define H_S      LALT_T(KC_S)
#define H_D      LCTL_T(KC_D)
#define H_F      LSFT_T(KC_F)
#define H_G      LT(_LOWER_LAYER, KC_G)
#define H_H      LT(_RAISE_LAYER, KC_H)
#define H_J      LSFT_T(KC_J)
#define H_K      LCTL_T(KC_K)
#define H_L      LALT_T(KC_L)
#define H_SCLN   LGUI_T(KC_SCLN)
#define SPC_NAV  LT(_NAVIGATION_LAYER, KC_SPACE)

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_LAYER] = LAYOUT( \
// |-----------------------------------------------------|                 |-----------------------------------------------------|
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    GUI_ESC, H_A,     H_S,     H_D,      H_F,    H_G,                       H_H,     H_J,     H_K,     H_L,     H_SCLN,  KC_QUOT,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    KC_UNDS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MINS_SFT,
// |--------|--------|--------|--------|--------|--------|--------+--------|--------|--------|--------|--------|--------|--------|
                                        L_UI,    BSP_LOW, ENT_SFT, SPC_NAV, DEL_RSE, L_UI
//                                     |--------------------------+--------------------------|
),

  [_LOWER_LAYER] = LAYOUT(
// |-----------------------------------------------------|                 |-----------------------------------------------------|
    GUI_TAB, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,                     GUI_6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, GUI_7,   GUI_8,   GUI_9,   GUI_0,   ___X___,                   ___X___, ___X___, _______, _______, _______, _______,
// |--------|--------|--------|--------|--------|--------|--------+--------|--------|--------|--------|--------|--------|--------|
                                        _______, _______, _______, _______, _______, _______
//                                     |--------------------------+--------------------------|
),

[_RAISE_LAYER] = LAYOUT(
// |-----------------------------------------------------|                 |-----------------------------------------------------|
    GUI_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  ___X___, _______, _______, _______, _______,
// |--------|--------|--------|--------|--------|--------|--------+--------|--------|--------|--------|--------|--------|--------|
                                        _______, _______, _______, _______, _______, _______
//                                     |--------------------------+--------------------------|
),

[_NAVIGATION_LAYER] = LAYOUT(
// |-----------------------------------------------------|                 |-----------------------------------------------------|
    _______, ___X___, ___X___, ___X___, ___X___, ___X___,                   ___X___, KC_HOME, KC_UP,   KC_END,  ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___X___,                   ___X___, KC_LEFT, KC_DOWN, KC_RGHT, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, ___X___, ___X___, ___X___, ___X___, ___X___,                   ___X___, KC_PGDN, ___X___, KC_PGUP, ___X___, ___X___,
// |--------|--------|--------|--------|--------|--------|--------+--------|--------|--------|--------|--------|--------|--------|
                                        _______, _______, _______, _______, _______, _______
//                                     |--------------------------+--------------------------|
),

[_UI_LAYER] = LAYOUT(
// |-----------------------------------------------------|                 |-----------------------------------------------------|
    RESET,   RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, ___X___,                   ___X___, GUI_LBR, WIN_UP,  GUI_RBR, GUI_MIN, GUI_EQL,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    _______, KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,                   ___X___, WIN_LEFT,WIN_DOWN,WIN_RGHT,GUI_TAB, GUI_GRV,
// |--------|--------|--------|--------|--------|--------|                 |--------|--------|--------|--------|--------|--------|
    KC_CAPS, GUI_SSF, GUI_SST, ___X___, ___X___, ___X___,                   ___X___, ___X___, ___X___, ___X___, ___X___, KC_CAPS,
// |--------|--------|--------|--------|--------|--------|--------+--------|--------|--------|--------|--------|--------|--------|
                                        _______, KC_MUTE, KC_F14,  KC_F15,  KC_MUTE, _______
//                                     |--------------------------+--------------------------|
),
};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case ENT_SFT:
        return TAPPING_TERM - 100;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){

  }
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}