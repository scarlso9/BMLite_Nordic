/*
 * Copyright (c) 2020 Fingerprint Cards AB
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PLATFORM_H
#define PLATFORM_H

/**
 * @file    platform.h
 * @brief   Platform specific function interface
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "fpc_bep_types.h"

/**
 * @brief LED status.
 *
 * Different LED status.
 */
typedef enum {
    BMLITE_LED_STATUS_READY = 0,
    BMLITE_LED_STATUS_MATCH,
    BMLITE_LED_STATUS_WAITTOUCH,
    BMLITE_LED_STATUS_ENROLL,
    BMLITE_LED_STATUS_DELETE_TEMPLATES,
    BMLITE_LED_STATUS_ERROR,
} platform_led_status_t;

/**
 * @brief Initializes board
 *
 * @param[in]       speed_hz    Baudrate.
 */
bool platform_init(uint32_t speed_hz);

/**
 * @brief Does BM-Lite HW Reset
 *
 */
void platform_bmlite_reset(void);

/**
 * @brief Sends data over communication port in blocking mode.
 *
 * @param[in]       size        Number of bytes to send.
 * @param[in]       data        Data buffer to send.
 * @param[in]       timeout     Timeout in ms. Use 0 for infinity.
 *
 * @return ::fpc_com_result_t
 */
fpc_bep_result_t platform_bmlite_send(uint16_t size, const uint8_t *data, uint32_t timeout,
        void *session);

/**
 * @brief Receives data from communication port in blocking mode.
 *
 * @param[in]       size        Number of bytes to receive.
 * @param[in, out]  data        Data buffer to fill.
 * @param[in]       timeout     Timeout in ms. Use 0 for infinity.
 *
 * @return ::fpc_com_result_t
 */
fpc_bep_result_t platform_bmlite_receive(uint16_t size, uint8_t *data, uint32_t timeout,
        void *session);

/**
 * @brief Stops execution if a debug interface is attached.
 */
void platform_halt_if_debug(void);

/**
 * @brief Performs a software reset.
 */
void platform_sw_reset(void) __attribute__((__noreturn__));

/**
 * @brief Get button press time.
 *
 * @return Button press time in milli seconds.
 */
uint32_t platform_get_button_press_time(void);

/**
 * @brief Check if button was pressed and released.
 *
 * @return Button press time in milli seconds.
 */
uint32_t platform_check_button_pressed(void);


#endif /* PLATFORM_H */
