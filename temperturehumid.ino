
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// DHT22 sensor connections
#define DHTPIN 4
#define DHTTYPE DHT22

// OLED I2C connections
#define OLED_SDA 21
#define OLED_SCL 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {
  Serial.begin(115200);

  // Initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED initialization failed!");
    while (true) {
      delay(100);
    }
  }

  // Startup screen
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 15);
  display.println("ESP32 Environment");
  display.setCursor(25, 30);
  display.println("Temperature");
  display.setCursor(35, 42);
  display.println("& Humidity");
  display.display();

  dht.begin();
  delay(2000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check sensor readings
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 sensor error!");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(10, 20);
    display.println("Sensor Error!");
    display.setCursor(10, 35);
    display.println("Check DHT22 wiring");
    display.display();

    delay(2000);
    return;
  }

  // Serial Monitor output
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  // OLED display
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("TEMP & HUMIDITY");
  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  display.setCursor(0, 20);
  display.print("Temperature:");

  display.setTextSize(2);
  display.setCursor(0, 31);
  display.print(temperature, 1);
  display.print(" C");

  display.setTextSize(1);
  display.setCursor(0, 55);
  display.print("Humidity: ");
  display.print(humidity, 1);
  display.print("%");

  display.display();

  delay(2500);
}
