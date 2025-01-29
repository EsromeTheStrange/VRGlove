#include <Arduino.h>
#include <NimBLEHIDDevice.h>
#include <NimBLEDevice.h>

#include "device_info.h"

#define GLOVE_NAME "VR Glove"
#define GLOVE_MANUFACTURER "Caleb, Maika"

NimBLEHIDDevice *glove;

void setup() {
  Serial.begin(115200);
  Serial.println("VR Glove Initializing...");

  NimBLEDevice::init(GLOVE_NAME);
  NimBLEServer *pServer = NimBLEDevice::createServer();
  //pServer->setCallbacks()

  //Get Input Report

  //Get Output Report

  //Custom HID Report Stuff Here

  glove = new NimBLEHIDDevice(pServer);
  glove->setManufacturer(GLOVE_MANUFACTURER);

  SetDeviceInfo(pServer);

  glove->setHidInfo(0x00, 0x01);
  //glove->setPnp

  NimBLEDevice::setSecurityAuth(true, false, true);

  glove->startServices();
  
  NimBLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->setAppearance(HID_GAMEPAD);
  pAdvertising->setName(GLOVE_NAME);
  pAdvertising->addServiceUUID(glove->getHidService()->getUUID());
  pAdvertising->enableScanResponse(true);
  pAdvertising->start();
}

void loop() {
}