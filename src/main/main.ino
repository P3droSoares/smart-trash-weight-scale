#include <HX711.h>

#define DOUT_PIN 2
#define SCK_PIN 3

HX711 scale;

float knowWeight = 200;

void setup(){
    Serial.begin(9600);
    scale.begin(DOUT_PIN, SCK_PIN);

    while(!Serial.available()){
        delay(10);
    }

    scale.get_units(10);

    float weight1 = scale.get_units(10);
    scale.set_scale(knowWeight / weight1);
    scale.tare();
    Serial.println("Calibração do peso conhecido 1 concluída.");
}

void loop() {
    float weight = scale.get_units();  // Lê o valor da célula de carga
    Serial.println("Peso: " + String(weight) + " g");
}
