/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_MUTE,    HYPR(KC_S), HYPR(KC_A),
        KC_MPRV,    KC_MPLY,    KC_MNXT,
        HYPR(KC_P), HYPR(KC_M), KC_TRNS
    ),
    LAYOUT(
        _______,       _______,      _______,
        HYPR(KC_LEFT), HYPR(KC_SPC), HYPR(KC_RIGHT),
        _______,       _______,      KC_TRNS
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code16(KC_VOLU);
  } else {
    tap_code16(KC_VOLD);
  }
}
