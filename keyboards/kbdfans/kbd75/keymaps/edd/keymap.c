#include QMK_KEYBOARD_H
#include "process_unicode_common.h"

extern rgblight_config_t rgblight_config;

#define LT1S LT(1,KC_SPC)
#define KILL LGUI(LALT(KC_ESC))
#define UMLX UNICODE_MODE_LNX
#define UMOX UNICODE_MODE_OSX
#define NKRO MAGIC_TOGGLE_NKRO

// layernames
enum {
      _BASE = 0,
      _FUNC,
      _SYMB,
      _MACR,
      NLYRS
};

enum custom_keycodes {
    KC_MR = SAFE_RANGE,
    KC_IM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case KC_MR:
       if (record->event.pressed) {
        SEND_STRING("Revert and reapply.");
      } else {}
      break;
     case KC_IM:
       tap_code16(HYPR(KC_SPC));
       rgblight_set_layer_state(3, rgblight_get_layer_state(0));
  }
  return true;
};

// light 10-13 red when input method is changed
const rgblight_segment_t PROGMEM inputmethod_layer[] = RGBLIGHT_LAYER_SEGMENTS({10,4,HSV_RED});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] =
  RGBLIGHT_LAYERS_LIST(RGBLIGHT_LAYER_SEGMENTS({0,15,12,255,255}),
                       RGBLIGHT_LAYER_SEGMENTS({0,15,132,255,255}),
                       RGBLIGHT_LAYER_SEGMENTS({0,15,220,255,255}),
                       inputmethod_layer
);


void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(12, 225, 255);
  rgblight_layers = my_rgb_layers;
}

uint32_t layer_state_set_user(uint32_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  rgblight_set_layer_state(1, layer_state_cmp(state, 1));
  rgblight_set_layer_state(2, layer_state_cmp(state, 2));
 
  return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
    LT(2,KC_ESC),  KC_F1,         KC_F2,      KC_F3,       KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,      KC_F12,     KC_DEL,       KC_PSCR,         KC_PAUS,
    KC_GRV,        KC_1,          KC_2,       KC_3,        KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,        KC_MINS,     KC_EQL,     KC_DEL,       KC_BSPC,         KC_HOME,
    ALT_T(KC_TAB), KC_Q,          KC_W,       KC_E,        KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,        KC_LBRC,     KC_RBRC, RALT_T(KC_BSLS),                  KC_PGUP,
    CTL_T(KC_ESC), KC_A,          KC_S,       KC_D,        KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,     KC_QUOT,                               RCTL_T(KC_ENT),  KC_PGDN,
    KC_LSPO,       LT(2,KC_APP),  KC_Z,       KC_X,        KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSPC,                  KC_UP,           KC_END,
    KC_LCTL,       KC_LGUI,       KC_LALT,                             LT1S,       KC_LGUI,    LT1S,                               KC_RALT,     KC_RGUI,     KC_RCTL,    KC_LEFT,      KC_DOWN,         KC_RGHT
  ),

  LAYOUT(
    KC_SLEP,       HYPR(KC_E),    HYPR(KC_F), HYPR(KC_M),  HYPR(KC_X), KC_F17,     KC_F18,     KC_F19,     KC_F20,     KC_F21,     KC_F22,      KC_F23,      KC_F24,     KC_INS,       KC_SLCK,         KILL,
    OSL(2),        RGB_TOG,       RGB_M_P,    RGB_M_B,     RGB_M_SW,   RGB_M_K,    RGB_M_G,    RGB_HUI,    RGB_HUD,    RGB_SAI,    RGB_SAD,     RGB_VAD,     RGB_VAI,    RESET,        RESET,           DEBUG,
    KC_NO,         HYPR(KC_Q),    HYPR(KC_W), HYPR(KC_E),  HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P),  RGB_SPD,     RGB_SPI,    EEP_RST,                       KC_BRIU,
    UMLX,          HYPR(KC_A),    HYPR(KC_S), HYPR(KC_D),  HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), KC_NO,       KC_NO,                              UMOX,            KC_BRID,
    KC_MUTE,       KC_NO,         HYPR(KC_Z), HYPR(KC_X),  HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), KC_NO,      KC_NO,       KC_NO,       KC_MPLY,                  KC_VOLU,         NKRO,
    OSL(2),        KC_NO,         KC_NO,                               KC_SLEP,    KC_IM,       KC_SLEP,                            KC_NO,       KC_NO,       KC_TRNS,    KC_MRWD,      KC_VOLD,         KC_MFFD
  )
};
