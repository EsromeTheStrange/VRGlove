#define LOGGER_PREFIX "VRGlove: "

class VRGloveLogger{
public:
    static void Log(const char* message){
        Serial.print(LOGGER_PREFIX);
        Serial.println(message);
    };
};