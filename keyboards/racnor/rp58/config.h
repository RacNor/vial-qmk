#pragma once

// Options not yet fully implemented in info.json
#define RGBLIGHT_LIMIT_VAL 175
#define RGBLIGHT_DEFAULT_VAL ( RGBLIGHT_LIMIT_VAL / 2 )

#define SPLIT_HAND_PIN GP9
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define SERIAL_USART_TX_PIN GP1
#define SERIAL_PIO_USE_PIO1
#define USB_VBUS_PIN GP19