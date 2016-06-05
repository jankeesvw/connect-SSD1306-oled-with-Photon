#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_MOSI   D0
#define OLED_CLK   D1
#define OLED_DC    D2
#define OLED_CS    D3
#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int setLines(String lines) {
  display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  String input = lines;
  int lastMatch = 0;

  // A comma is used as a line seperator. "Hello,World" gets:
  // Hello
  // World
  for (int i = 0; i < input.length(); i++) {
    if (input.substring(i, i + 1) == ",") {
      display.println(input.substring(lastMatch, i));
      lastMatch = i + 1;
    }

    // done
    if(i == input.length() - 1){
      display.println(input.substring(lastMatch, i + 1));
    }
  }

  display.display();
  return 1;
}

void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);

  setLines("Hello,World");
}

void loop() {
}
