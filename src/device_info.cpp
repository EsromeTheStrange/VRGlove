#include "device_info.h"

void SetDeviceInfo(NimBLEServer *pServer){
    NimBLEService *pService = pServer->getServiceByUUID(SERVICE_UUID_DEVICE_INFORMATION);

  NimBLECharacteristic* pCharacteristic_Model_Number = pService->createCharacteristic(
    CHARACTERISTIC_UUID_MODEL_NUMBER,
    NIMBLE_PROPERTY::READ
  );
  pCharacteristic_Model_Number->setValue(MODEL_NUMBER);

  NimBLECharacteristic* pCharacteristic_Software_Revision = pService->createCharacteristic(
    CHARACTERISTIC_UUID_SOFTWARE_REVISION,
    NIMBLE_PROPERTY::READ
  );
  pCharacteristic_Software_Revision->setValue(SOFTWARE_REVISION);

  NimBLECharacteristic* pCharacteristic_Serial_Number = pService->createCharacteristic(
    CHARACTERISTIC_UUID_SERIAL_NUMBER,
    NIMBLE_PROPERTY::READ
  );
  pCharacteristic_Serial_Number->setValue(SERIAL_NUMBER);

  NimBLECharacteristic* pCharacteristic_Firmware_Revision = pService->createCharacteristic(
    CHARACTERISTIC_UUID_FIRMWARE_REVISION,
    NIMBLE_PROPERTY::READ
  );
  pCharacteristic_Firmware_Revision->setValue(FIRMWARE_REVISION);

  NimBLECharacteristic* pCharacteristic_Hardware_Revision = pService->createCharacteristic(
    CHARACTERISTIC_UUID_HARDWARE_REVISION,
    NIMBLE_PROPERTY::READ
  );
  pCharacteristic_Hardware_Revision->setValue(HARDWARE_REVISION);
}