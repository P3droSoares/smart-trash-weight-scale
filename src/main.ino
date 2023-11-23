#include <HX711.h>

#define DOUT_PIN 2
#define SCK_PIN 3

void setup(){
    Serial.begin(9600);
    scale.begin(DOUT_PIN, SCK_PIN);

    scale.set_scale();
}