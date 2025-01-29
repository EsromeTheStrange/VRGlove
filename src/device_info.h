#include <NimBLEDevice.h>

#define SERVICE_UUID_DEVICE_INFORMATION        "180A"      // Service - Device information

#define CHARACTERISTIC_UUID_MODEL_NUMBER       "2A24"      // Characteristic - Model Number String - 0x2A24
#define CHARACTERISTIC_UUID_SOFTWARE_REVISION  "2A28"      // Characteristic - Software Revision String - 0x2A28
#define CHARACTERISTIC_UUID_SERIAL_NUMBER      "2A25"      // Characteristic - Serial Number String - 0x2A25
#define CHARACTERISTIC_UUID_FIRMWARE_REVISION  "2A26"      // Characteristic - Firmware Revision String - 0x2A26
#define CHARACTERISTIC_UUID_HARDWARE_REVISION  "2A27"      // Characteristic - Hardware Revision String - 0x2A27

#define MODEL_NUMBER "1.0.0"
#define SOFTWARE_REVISION "1.0.0"
#define FIRMWARE_REVISION "1.0.0"
#define HARDWARE_REVISION "1.0.0"
#define SERIAL_NUMBER "0123456789"

void SetDeviceInfo(NimBLEServer *pServer);