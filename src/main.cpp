#include <Arduino.h>
#include <NimBLEHIDDevice.h>
#include <NimBLEDevice.h>

#define GLOVE_NAME "VR Glove"

#define SERVICE_UUID_DEVICE_INFORMATION        "180A"      // Service - Device information

#define CHARACTERISTIC_UUID_MODEL_NUMBER       "2A24"      // Characteristic - Model Number String - 0x2A24
#define CHARACTERISTIC_UUID_SOFTWARE_REVISION  "2A28"      // Characteristic - Software Revision String - 0x2A28
#define CHARACTERISTIC_UUID_SERIAL_NUMBER      "2A25"      // Characteristic - Serial Number String - 0x2A25
#define CHARACTERISTIC_UUID_FIRMWARE_REVISION  "2A26"      // Characteristic - Firmware Revision String - 0x2A26
#define CHARACTERISTIC_UUID_HARDWARE_REVISION  "2A27"      // Characteristic - Hardware Revision String - 0x2A27

#define MODEL_NUMBER "1.0.0"
#define SOFTWARE_REVISION "1.0.0"
#define SERIAL_NUMBER "0123456789"
#define FIRMWARE_REVISION "0.6.3"
#define HARDWARE_REVISION "1.0.0"

NimBLEHIDDevice *glove;

void setup() {
    Serial.begin(115200);
    Serial.println("VR Glove Initializing...");

    NimBLEDevice::init(GLOVE_NAME);
    NimBLEServer *pServer = NimBLEDevice::createServer();
    //pServer->setCallbacks

    //Get Input Report

    //Get Output Report

    //Custom HID Report Stuff Here

    glove = new NimBLEHIDDevice(pServer);
    glove->setManufacturer("Caleb, Maika");

    NimBLEService *pService = pServer->getServiceByUUID(SERVICE_UUID_DEVICE_INFORMATION);

	BLECharacteristic* pCharacteristic_Model_Number = pService->createCharacteristic(
      CHARACTERISTIC_UUID_MODEL_NUMBER,
      NIMBLE_PROPERTY::READ
    );
    pCharacteristic_Model_Number->setValue(MODEL_NUMBER);

    BLECharacteristic* pCharacteristic_Software_Revision = pService->createCharacteristic(
      CHARACTERISTIC_UUID_SOFTWARE_REVISION,
      NIMBLE_PROPERTY::READ
    );
    pCharacteristic_Software_Revision->setValue(SOFTWARE_REVISION);

    BLECharacteristic* pCharacteristic_Serial_Number = pService->createCharacteristic(
      CHARACTERISTIC_UUID_SERIAL_NUMBER,
      NIMBLE_PROPERTY::READ
    );
    pCharacteristic_Serial_Number->setValue(SERIAL_NUMBER);
	
	BLECharacteristic* pCharacteristic_Firmware_Revision = pService->createCharacteristic(
      CHARACTERISTIC_UUID_FIRMWARE_REVISION,
      NIMBLE_PROPERTY::READ
    );
    pCharacteristic_Firmware_Revision->setValue(FIRMWARE_REVISION);
	
	BLECharacteristic* pCharacteristic_Hardware_Revision = pService->createCharacteristic(
      CHARACTERISTIC_UUID_HARDWARE_REVISION,
      NIMBLE_PROPERTY::READ
    );
    pCharacteristic_Hardware_Revision->setValue(HARDWARE_REVISION);

    glove->setHidInfo(0x00, 0x01);
    //glove->setPnp

    NimBLEDevice::setSecurityAuth(true, false, false);

    glove->startServices();
    
    NimBLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->setAppearance(HID_GAMEPAD);
    pAdvertising->setName(GLOVE_NAME);
    pAdvertising->addServiceUUID(glove->getHidService()->getUUID());
    pAdvertising->start();
}

void loop() {
}