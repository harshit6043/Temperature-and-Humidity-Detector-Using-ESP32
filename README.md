# Temperature and Humidity Detector Using ESP32

An ESP32-based environmental monitoring project that measures temperature and relative humidity using a DHT22 sensor and displays live readings on a 0.96-inch 128×64 OLED display.

## Features

- Real-time temperature measurement in Celsius
- Relative humidity measurement in percentage
- OLED display using I²C communication
- Serial Monitor output for debugging
- Sensor error detection
- Expandable for future IoT monitoring

## Components Required

| Component | Quantity |
|---|---:|
| ESP32 development board | 1 |
| DHT22 / AM2302 sensor | 1 |
| 0.96-inch 128×64 SSD1306 I²C OLED | 1 |
| Breadboard | 1 |
| Jumper wires | As required |
| USB data cable | 1 |
| 4.7–10 kΩ resistor, if needed | 1 |

## Wiring Connections

### DHT22 to ESP32

| DHT22 | ESP32 |
|---|---|
| VCC | 3V3 |
| DATA | GPIO 4 |
| GND | GND |

### OLED to ESP32

| OLED | ESP32 |
|---|---|
| GND | GND |
| VCC | 3V3 |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

These are proposed connections for a typical ESP32 DevKit V1. Confirm the board pinout and your OLED module's pin labels before powering the circuit.

A bare DHT22 normally needs a pull-up resistor between DATA and 3.3 V. Many sensor modules include one already.

## Software Requirements

- Arduino IDE
- ESP32 board support package
- Adafruit SSD1306
- Adafruit GFX Library
- DHT sensor library by Adafruit
- Adafruit Unified Sensor

## Installation and Setup

1. Install Arduino IDE.
2. Install ESP32 support through Boards Manager.
3. Install the required libraries through Library Manager.
4. Connect the sensor and OLED according to the wiring tables.
5. Open `Temperature_Humidity_ESP32.ino`.
6. Select your ESP32 board and serial port.
7. Upload the program.
8. Open Serial Monitor at 115200 baud.

## How It Works

The DHT22 measures the surrounding temperature and relative humidity. The ESP32 reads the sensor data, prints the readings to the Serial Monitor, and updates the OLED display.

The display shows temperature in degrees Celsius and humidity as a percentage.

## Applications

- Indoor environmental monitoring
- Smart home projects
- Greenhouse monitoring
- Classroom and laboratory experiments
- IoT environmental monitoring prototypes

## Troubleshooting

- **Blank OLED:** Verify I²C wiring and check the display address.
- **Sensor errors:** Check DHT22 wiring, sensor type, and DATA connection.
- **Compilation errors:** Verify all required libraries are installed.
- **Upload errors:** Check the USB cable, COM port, and board selection.

## Future Improvements

- Add Wi-Fi-based remote monitoring.
- Integrate Blynk or a web dashboard.
- Add configurable temperature and humidity alerts.
- Record sensor readings for historical analysis.



## Author

harshit 23001008019

## License

.
