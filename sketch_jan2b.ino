#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Configura el sensor DHT11
#define DHTPIN 2
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);

// Configura la pantalla LCD 16x2 I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicializa el sensor DHT11
  dht.begin();

  // Inicializa la pantalla LCD
  lcd.init();
  lcd.backlight();

  // Muestra un mensaje de inicio en la pantalla
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
}

void loop() {
  // Lee los datos del sensor DHT11
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temperatura = event.temperature;
  dht.humidity().getEvent(&event);
  float humedad = event.relative_humidity;

  // Actualiza la pantalla con los valores
  lcd.setCursor(6, 0);
  lcd.print(temperatura, 1);
  lcd.print(" C");
  lcd.setCursor(9, 1);
  lcd.print(humedad, 1);
  lcd.print(" %");

  delay(1000); // Espera 1 segundos antes de la siguiente lectura
}
