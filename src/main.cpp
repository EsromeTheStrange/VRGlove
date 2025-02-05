#include <Arduino.h>

#include "vr_glove.h"

#define GLOVE_NAME "VR Glove"
#define GLOVE_MANUFACTURER "Caleb, Maika"

VRGloveDevice *glove;

void setup() {
    Serial.begin(115200);
    Serial.println("VR Glove Initializing...");

    glove = new VRGloveDevice(GLOVE_NAME, GLOVE_MANUFACTURER);
}

void loop() {
}