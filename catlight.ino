#include <Adafruit_NeoPixel.h>

#define PIN 10
#define LEDS 3

int DATA = 0;
int LICENCE = 80;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(9800);
	strip.begin();
	strip.clear();
	strip.show();
}

void loop()
{
	if (Serial.available()) {
		DATA = Serial.parseInt();
		//int junk = Serial.read();			//"Enter" entfernen
		Serial.print(DATA);
		Serial.print("\n");
		if (DATA > LICENCE) {
			Serial.print("Wert zu hoch!!!");
		}
		else {
			if (DATA <= (LICENCE / 2)) {
				int value = ((DATA * 255) / LICENCE) * 2;
				strip.setPixelColor(0, (0 + value), 255, 0);
				strip.setPixelColor(1, (0 + value), 255, 0);
				strip.setPixelColor(2, (0 + value), 255, 0);
			}
			else {
				int value = ((DATA * 255) / LICENCE) * 2;
				strip.setPixelColor(0, 255, (255 - value), 0);
				strip.setPixelColor(1, 255, (255 - value), 0);
				strip.setPixelColor(2, 255, (255 - value), 0);
			}
			strip.setBrightness(100);
			strip.show();
		}
	}
}
