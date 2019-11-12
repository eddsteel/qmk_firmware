#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;

const uint16_t LT1S = LT(1,KC_SPC);
const uint16_t KILL = LGUI(LALT(KC_ESC));
const uint16_t UMLX = UNICODE_MODE_LNX;
const uint16_t UMOX = UNICODE_MODE_OSX;
const uint16_t NKRO = MAGIC_TOGGLE_NKRO;

// layernames
enum {
      _BASE = 0,
      _FUNC,
      _SYMB,
      _MACR,
      NLYRS
};
// hues, 1 per layer
const uint8_t HUES[] = { 0, 132, 220, 96 };


void matrix_init_user() {
  set_unicode_input_mode(UC_LNX);
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HUES[_BASE], 165, 255);
};

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t n = get_highest_layer(state);
  if (n < NLYRS) {
    rgblight_sethsv_noeeprom(HUES[n], 165, 255);
  } else {
    rgblight_sethsv_noeeprom(HUES[_BASE], 165, 255);
  }

  return state;
}

// flags are multiple characters, so leave them out of this
enum unicode_names {
  GRIN,
  LAUGH,
  HAPPY,
  SAD,
  WINK,
  TONGUE,
  FPALM,
  BLANK,
  BRO,
  ANGRY,
  CRY,
  SOB,
  PARTY,
  LQ,
  RQ,
  LDQ,
  RDQ,
  EN,
  EM,
  COOL,
  SAX,
  SGLASS,
  NERD,
  SNOW,
  HDS,
  VDS,
  INTB,
  GHOST,
  HEART,
  TADA
};
// only first 127 can be used with shift.

const uint32_t PROGMEM unicode_map[] = {
  [GRIN]   = 0x1f600, // 😀
  [LAUGH]  = 0x1f604, // 😄
  [HAPPY]  = 0x1f642, // 🙂
  [SAD]    = 0x1f641, // 🙁
  [WINK]   = 0x1f609, // 😉
  [TONGUE] = 0x1f61b, // 😛
  [FPALM]  = 0x1f926, // 🤦
  [BLANK]  = 0x1f611, // 😑
  [BRO]    = 0x1f928, // 🤨
  [CRY]    = 0x1f622, // 😢
  [SOB]    = 0x1f62d, // 😭
  [PARTY]  = 0x1f973, // 🥳
  [TADA]   = 0x1f389, // 🎉
  [LQ]     = 0x2018 , // ‘
  [RQ]     = 0x2019 , // ’
  [LDQ]    = 0x201c , // “
  [RDQ]    = 0x201d , // ”
  [EN]     = 0x2013 , // –
  [EM]     = 0x2014 , // —
  [COOL]   = 0x1f60e, // 😎
  [SAX]    = 0x1f3b7, // 🎷
  [SGLASS] = 0x1f576, // 🕶
  [NERD]   = 0x1f913, // 🤓
  [HDS]    = 0x2026 , // …
  [VDS]    = 0x22ee , // ⋮
  [INTB]   = 0x203d , // ‽
  [SNOW]   = 0x2603 , // ☃
  [GHOST]  = 0x1f47b, // 👻
  [HEART]  = 0x2764 , // ❤
  [ANGRY]  = 0x1f620  // 😠
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    LT(2,KC_ESC),  KC_F1,         KC_F2,      KC_F3,       KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,      KC_F12,     KC_DEL,       KC_PSCR,         KC_PAUS,
    KC_GRV,        KC_1,          KC_2,       KC_3,        KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,        KC_MINS,     KC_EQL,     KC_DEL,       KC_BSPC,         KC_HOME,
    ALT_T(KC_TAB), KC_Q,          KC_W,       KC_E,        KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,        KC_LBRC,     KC_RBRC, RALT_T(KC_BSLS),                  KC_PGUP,
    CTL_T(KC_ESC), KC_A,          KC_S,       KC_D,        KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,     KC_QUOT,                               RCTL_T(KC_ENT),  KC_PGDN,
                                                                   KC_LSPO,       LT(2,KC_MENU), KC_Z,       KC_X,        KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,      KC_SLSH,     KC_RSPC,                  KC_UP,           KC_END,
    KC_LCTL,       KC_LGUI,       KC_LALT,                             LT1S,       LT1S,       LT1S,                               KC_RALT,     KC_RGUI,     MO(1),      KC_LEFT,      KC_DOWN,         KC_RGHT
  ),

  [1] = LAYOUT(
    KC_SLEP,       KC_F13,        KC_F14,     KC_F15,      KC_F16,     KC_F17,     KC_F18,     KC_F19,     KC_F20,     KC_F21,     KC_F22,      KC_F23,      KC_F24,     KC_INS,       KC_SLCK,         KILL,
    OSL(2),        RGB_TOG,       RGB_M_P,    RGB_M_B,     RGB_M_SW,   RGB_M_K,    RGB_M_G,    RGB_HUI,    RGB_HUD,    RGB_SAI,    RGB_SAD,     RGB_VAD,     RGB_VAI,    RESET,        RESET,           DEBUG,
    KC_NO,         HYPR(KC_Q),    HYPR(KC_W), HYPR(KC_E),  HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P),  RGB_SPD,     RGB_SPI,    EEP_RST,                       NKRO,
    UMLX,          HYPR(KC_A),    HYPR(KC_S), HYPR(KC_D),  HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), KC_NO,       KC_NO,                                 UMOX,            KC_BRIU,
    KC_MUTE,       KC_NO,         HYPR(KC_Z), HYPR(KC_X),  HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), KC_NO,      KC_NO,       KC_NO,       KC_MPLY,                  KC_VOLU,         KC_BRID,
    OSL(3),        KC_NO,         KC_NO,                               KC_SLEP,    KC_SLEP,    KC_SLEP,                            KC_NO,       KC_NO,       KC_TRNS,    KC_MRWD,      KC_VOLD,         KC_MFFD
  ),

  [2] = LAYOUT(
    KC_TRNS,       KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_TRNS,
    OSL(3),        KC_NO,         KC_NO,      X(HEART),    KC_NO,      KC_NO,   XP(BRO,ANGRY), X(GHOST),XP(NERD,SNOW), X(SAD),     X(HAPPY),    XP(EN,EM),   KC_NO,      KC_NO,        KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      X(TONGUE),   XP(LQ,LDQ),  XP(RQ,RDQ), X(BLANK),                      KC_NO,
    KC_NO,         KC_NO,         KC_NO,   XP(GRIN,LAUGH), X(FPALM),   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      X(WINK),     XP(CRY,SOB),                           KC_NO,           KC_NO,
    KC_NO,         KC_TRNS,       KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  XP(PARTY,TADA), XP(HDS,VDS), X(INTB),     KC_NO,                    KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,                               KC_NO,      KC_NO,      KC_NO,                              KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_NO
   ),

  [3] = LAYOUT(
    KC_TRNS,       KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_TRNS,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,                         KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,                                 KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,                    KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,                               KC_NO,      KC_NO,      KC_NO,                              KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_NO
  )
};




