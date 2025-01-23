#include "report_descriptor.h"
#include <Arduino.h>

#include <esp_log.h>
#define LOG_LIB "VR Glove"


#include <esp_gap_bt_api.h>
#include <esp_hidd_api.h>
////#include <esp_bt_main.h>
////#include <esp_bt_device.h>

#define REPORT_BUFFER_SIZE (4)

typedef struct {
    esp_hidd_app_param_t app_param;
    esp_hidd_qos_param_t both_qos;
    uint8_t protocol_mode;
    SemaphoreHandle_t mouse_mutex;
    TaskHandle_t mouse_task_hdl;
    uint8_t buffer[REPORT_BUFFER_SIZE];
    int8_t x_dir;
} AppParameters;

static AppParameters s_appParams = {0};

void esp_bt_hidd_cb(esp_hidd_cb_event_t event, esp_hidd_cb_param_t *param)
{
    const char* LOG_TAG = "VR Glove: esp_bt_hidd_cb";
    switch (event) {
    case ESP_HIDD_INIT_EVT:
        if (param->init.status == ESP_HIDD_SUCCESS) {
            ESP_LOGI(LOG_TAG, "setting hid parameters");
            esp_bt_hid_device_register_app(&s_appParams.app_param, &s_appParams.both_qos, &s_appParams.both_qos);
        } else {
            ESP_LOGE(LOG_TAG, "init hidd failed!");
        }
        break;
    }
}

void setup() {
    const char* LOG_TAG = "VR Glove: setup";
    Serial.begin(115200);

    ESP_LOGI(LOG_TAG, "VR Glove Initializing...");

    ESP_LOGI(LOG_TAG, "setting Class of Device major, peripheral");
    esp_bt_cod_t cod;
    cod.major = ESP_BT_COD_MAJOR_DEV_PERIPHERAL;
    esp_bt_gap_set_cod(cod, ESP_BT_SET_COD_MAJOR_MINOR);

    // Initialize HID SDP information and L2CAP parameters.
    // to be used in the call of `esp_bt_hid_device_register_app` after profile initialization finishes
    do {
        s_appParams.app_param.name = "Mouse";
        s_appParams.app_param.description = "Mouse Example";
        s_appParams.app_param.provider = "ESP32";
        s_appParams.app_param.subclass = ESP_HID_CLASS_MIC;
        s_appParams.app_param.desc_list = vrGloveReportDescriptor;
        s_appParams.app_param.desc_list_len = sizeof(vrGloveReportDescriptor);

        memset(&s_appParams.both_qos, 0, sizeof(esp_hidd_qos_param_t)); // don't set the qos parameters
    } while (0);

    // Report Protocol Mode is the default mode, according to Bluetooth HID specification
    s_appParams.protocol_mode = ESP_HIDD_REPORT_MODE;

    ESP_LOGI(LOG_TAG, "register hid device callback");
    esp_bt_hid_device_register_callback(esp_bt_hidd_cb);

    ESP_LOGI(LOG_TAG, "starting hid device");
    esp_bt_hid_device_init();
}

void loop() {
}