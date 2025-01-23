#include <Arduino.h>
#include <NimBLEHIDDevice.h>
#include <NimBLEDevice.h>

NimBLEHIDDevice *glove;

void setup() {
    Serial.begin(115200);
    Serial.println("VR Glove Initializing...");

    NimBLEDevice::init("VR Glove");
    
    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService("ABCD");
    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("1234");

    glove = new NimBLEHIDDevice(pServer);
    glove->setManufacturer("Caleb, Maika");
    
    pService->start();
    pCharacteristic->setValue("Hello BLE");
    
    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID("ABCD"); // advertise the UUID of our service
    pAdvertising->setName("NimBLE"); // advertise the device name
    pAdvertising->start(); 
}

void loop() {
}