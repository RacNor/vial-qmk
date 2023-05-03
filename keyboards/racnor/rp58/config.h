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
//#undef I2C_DRIVER
//#define I2C_DRIVER I2CD0
//#undef I2C1_SCL_PIN
//#define I2C1_SCL_PIN GP2
//#undef I2C1_SDA_PIN
//#define I2C1_SDA_PIN GP3s