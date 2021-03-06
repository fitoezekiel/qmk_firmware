/* Copyright 2019 Ryota Goto
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
#include "kbd8x_mk2.h"

void matrix_init_kb(void) {  

  // Indicator pins
  // B2 - Scroll Lock
  // E6 - Caps Lock
  // Sinking setup - 5V -> LED/Resistor -> Pin
  
  setPinOutput(B2);
  setPinOutput(E6);

  matrix_init_user();
}

void led_set_kb(uint8_t usb_led) {
  
  // Toggle indicator LEDs
  // Since they are a sinking setup, write HIGH to DISABLE, LOW to ENABLE
  
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(E6);
  } else {
    writePinHigh(E6);
  }
  
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinLow(B2);
  } else {
    writePinHigh(B2);
  }

  led_set_user(usb_led);
}

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

*/
