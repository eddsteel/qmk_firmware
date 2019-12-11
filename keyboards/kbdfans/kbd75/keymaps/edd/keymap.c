#include QMK_KEYBOARD_H

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

// hues, 1 per layer
const uint8_t HUES[] = {12, 132, 220, 96 };

enum custom_keycodes {
    KC_MR = SAFE_RANGE,
    UC_TG,
    OS_KC_A,
    OS_KC_C,
    OS_KC_F,
    OS_KC_K,
    OS_KC_L,
    OS_KC_R,
    OS_KC_S,
    OS_KC_T,
    OS_KC_V,
    OS_KC_X,
    OS_KC_Z
};

uint16_t toggle_unicode(void) {
  uint16_t ret = LCAG(KC_L);
  switch (unicode_config.input_mode) {
  case UC_OSX:
  case UC_WIN:
  case UC_WINC:
    set_unicode_input_mode(UC_LNX);
    break;
  case UC_LNX:
    set_unicode_input_mode(UC_OSX);
    ret = LCAG(KC_X);
    break;
  }

  return ret;
}

void os_tap(uint16_t keycode) {
  if (unicode_config.input_mode == UC_OSX) {
    tap_code16(LGUI(keycode));
  } else {
    tap_code16(LCTL(keycode));
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case KC_MR:
       if (record->event.pressed) {
        SEND_STRING("Revert and reapply.");
      } else {}
      break;
  case UC_TG:
    if (record->event.pressed) {
      tap_code16(toggle_unicode());
    }
    break;
  case OS_KC_A:
    os_tap(KC_A);
    break;
  case OS_KC_C:
    os_tap(KC_C);
    break;
  case OS_KC_F:
    os_tap(KC_F);
    break;
  case OS_KC_V:
    os_tap(KC_V);
    break;
  case OS_KC_X:
    os_tap(KC_X);
    break;
  case OS_KC_L:
    os_tap(KC_L);
    break;
  case OS_KC_K:
    os_tap(KC_K);
    break;
  case OS_KC_R:
    os_tap(KC_R);
    break;
  case OS_KC_S:
    os_tap(KC_S);
    break;
  case OS_KC_T:
    os_tap(KC_T);
    break;
  case OS_KC_Z:
    os_tap(KC_Z);
    break;
  }
  return true;
};

void matrix_init_user() {
  set_unicode_input_mode(UC_LNX);
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HUES[_BASE], 225, 255);
}

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
    KC_NO,         HYPR(KC_Q),    HYPR(KC_W), HYPR(KC_E),  OS_KC_R,    OS_KC_T,    HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P),  RGB_SPD,     RGB_SPI,    EEP_RST,                       KC_BRIU,
    UMLX,          OS_KC_A,       OS_KC_S,    HYPR(KC_D),  OS_KC_F,    HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), OS_KC_K,    OS_KC_L,    KC_NO,       KC_NO,                                 UMOX,            KC_BRID,
    KC_MUTE,       KC_NO,         OS_KC_Z,    OS_KC_X,     OS_KC_C,    OS_KC_V,    HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), KC_NO,      KC_NO,       KC_NO,       KC_MPLY,                  KC_VOLU,         NKRO,
    OSL(3),        KC_NO,         KC_NO,                               KC_SLEP,    UC_TG,      KC_SLEP,                            KC_NO,       KC_NO,       KC_TRNS,    KC_MRWD,      KC_VOLD,         KC_MFFD
  ),

  LAYOUT(
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
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_MR,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,                         KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,                                 KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,      KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,       KC_NO,                    KC_NO,           KC_NO,
    KC_NO,         KC_NO,         KC_NO,                               KC_NO,      KC_NO,      KC_NO,                              KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,           KC_NO
  )
};
