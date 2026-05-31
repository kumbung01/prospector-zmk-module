#include <zephyr/types.h>
#include <zephyr/init.h>

#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);
#include <app_esb.h>
#include <zmk/events/split_central_status_changed.h>

static void peripheral_connected(int pipe) {
    raise_zmk_split_central_status_changed((struct zmk_split_central_status_changed){
        .slot = PIPE_TO_SOURCE(pipe),
        .connected = true,
    });
}

static void peripheral_disconnected(int pipe) {
    raise_zmk_split_central_status_changed((struct zmk_split_central_status_changed){
        .slot = PIPE_TO_SOURCE(pipe),
        .connected = false,
    });
}

static struct esb_conn_cb conn_cb = {
    .connected = peripheral_connected,
    .disconnected = peripheral_disconnected,
};

static int zmk_split_esb_central_init(void) {
    esb_conn_cb_register(&conn_cb);
    return 0;
}

SYS_INIT(zmk_split_esb_central_init, APPLICATION, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
