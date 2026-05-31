#pragma once
#include <zephyr/kernel.h>

#if !CONFIG_ZMK_BLE

#ifndef CONFIG_BT_MAX_PAIRED
#define CONFIG_BT_MAX_PAIRED 1
#endif

#ifndef ZMK_BLE_PROFILE_COUNT
#define ZMK_BLE_PROFILE_COUNT 1
#endif

// #ifndef ZMK_SPLIT_BLE_PERIPHERAL_COUNT
// #define ZMK_SPLIT_BLE_PERIPHERAL_COUNT 2
// #endif

#endif /* !CONFIG_ZMK_BLE */