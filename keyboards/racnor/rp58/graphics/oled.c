#include QMK_KEYBOARD_H
#include "os_detection.h"

#ifdef OLED_ENABLE

#define LAYER_STATE_SIZE 3

void render_layer(void) {
    switch(detected_host_os()) {
        case OS_MACOS:
          oled_write_P(PSTR("M\n"), false);
          break;
        case OS_LINUX:
          oled_write_P(PSTR("L\n"), false);
          break;
        case OS_WINDOWS:
          oled_write_P(PSTR("W\n"), false);
          break;
        case OS_IOS:
          oled_write_P(PSTR("I\n"), false);
          break;
        default:
          oled_write_P(PSTR("U\n"), false);
    }

    oled_write_P(PSTR("Fn:"), false);
    static char buff[LAYER_STATE_SIZE];
    get_numeric_str(buff, LAYER_STATE_SIZE, get_highest_layer(layer_state), ' ');
    oled_write(buff, false);
}
void render_status(void) {
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("C"), led_usb_state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S\n"), led_usb_state.scroll_lock);
}

static void print_status_narrow(void) {
    render_status();
    render_layer();
}

bool oled_task_user(void) {
    // Render the OLED
    print_status_narrow();
    return false;
}
#endif

