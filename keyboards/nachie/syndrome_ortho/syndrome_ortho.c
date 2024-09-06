/*
Copyright 2024 Nachie

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "quantum.h"


led_config_t g_led_config = { {
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    { 6, 5, 4, 3, 2, 1, 0, NO_LED },
    { 7,  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 15 },
    { 8 , 9, NO_LED, 10, 11, 12, 13, 14 },
    { NO_LED,  NO_LED,  NO_LED,NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    { 183,0 }, { 162,0 }, { 142,0 }, { 122,0 }, { 81,0 }, { 61,0 }, { 40,0 },
    { 20,16 }, { 40,48 },
    { 61,48 }, { 81,48 }, { 101,48 }, { 122,48 }, { 162,48 }, { 203,48 }, { 244,16 }
}, {
    1, 1, 1, 1, 1, 1, 1,
    1, 1,
    1, 1, 1, 1, 1, 1, 1
} };

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
   // 'Screenshot 2023-07-21 at 1', 128x32px
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xfe, 0x00, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0x3c, 0x00, 0x0f, 0x1f, 0xf8, 0xe0, 0x00, 0x1f, 0xff,
0xff, 0x80, 0x01, 0xc0, 0x00, 0x40, 0x00, 0x38, 0x00, 0x07, 0x1f, 0xf8, 0xe0, 0x00, 0x1f, 0xff,
0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0x0f, 0xff,
0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0x8f, 0xff,
0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0x0f, 0xff,
0xfe, 0x1f, 0xf1, 0xc0, 0x03, 0xff, 0x8f, 0xf8, 0xff, 0xc7, 0x1f, 0xf8, 0xe1, 0xc0, 0x1f, 0xff,
0xfe, 0x1f, 0xf1, 0xc0, 0x03, 0xff, 0x8f, 0xf8, 0xff, 0xc7, 0x1f, 0xf8, 0xe1, 0xe0, 0x3f, 0xff,
0xfe, 0x1f, 0xf1, 0xc3, 0xff, 0xff, 0x8f, 0xf8, 0xff, 0xc7, 0x1f, 0xf8, 0xe1, 0xf0, 0xff, 0xff,
0xfe, 0x1f, 0xf1, 0xc3, 0xff, 0xff, 0x8f, 0xf8, 0xff, 0xc7, 0x1f, 0xf8, 0xe1, 0xf8, 0x7f, 0xff,
0xfe, 0x1f, 0xf1, 0xc3, 0xff, 0xff, 0x8f, 0xf8, 0xff, 0xc7, 0x1f, 0xf8, 0xe1, 0xf8, 0x7f, 0xff,
0xfe, 0x00, 0x01, 0xc0, 0x00, 0x7f, 0x8f, 0xf8, 0x00, 0x07, 0x00, 0x00, 0xe1, 0xfc, 0x3f, 0xff,
0xfe, 0x00, 0x03, 0xc0, 0x00, 0xff, 0x8f, 0xfc, 0x00, 0x0f, 0x80, 0x01, 0xe1, 0xfe, 0x1f, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

bool oled_task_kb(void) {
    // Defer to the keymap if they want to override

     if(!oled_task_user()) {
        return false;
    }

    // default keyboard drawing code
    render_logo();
    return false;
}

#endif