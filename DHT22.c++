#include <DHTesp.h>

#define pinDHT 27

DHTesp dhtSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dhtSensor.setup(pinDHT, DHTesp::DHT22);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200); // this speeds up the simulation

  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  float temp = data.temperature;
  float hum = data.humidity;

  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Pembacaan Sensor DHT tidak Berhasil!"));
    return;
  }

  Serial.print("Kelembaban: ");
  Serial.print(hum);
  Serial.print("% \tSuhu: ");
  Serial.print(temp);
  Serial.print("°C ");
  Serial.println();
}
