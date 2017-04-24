// NeoPixel Snakes (c) 2017 Brian Gershon
// https://github.com/briangershon/neopixel-snakes.git

#include <Adafruit_NeoPixel.h>

#define PIN            8
#define NUMPIXELS      24

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  int red = random(25);
  int green = random(0);
  int blue = random(25);


  for(int i=0;i<NUMPIXELS;i+=1){
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
    delay(200);

  }

  delay(500);

  for(int i=NUMPIXELS-1;i>=0;i--){
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
  }

  // twinkling grass
  int brights[23];
  for(int i=0; i < NUMPIXELS-1; i++) {
    brights[i] = 0;
  }

  int snake_position = 0;
  int snake_position_two = 0;

  for(int i=0; i<100; i++) {
    int px = random(24);
    int direction = random(2);
    if (direction == 1) {
      brights[px]+=1;
      if (brights[px] > 40) { brights[px] = 40; }
    } else {
      brights[px]-=1;
      if (brights[px] < 0) { brights[px] = 0; }
    }
    pixels.setPixelColor(px, pixels.Color(0, brights[px], 0));

    pixels.setPixelColor(NUMPIXELS-1 + (snake_position_two % NUMPIXELS), pixels.Color(0, 0, 0));
    pixels.setPixelColor(NUMPIXELS-1 + ((snake_position_two - 1) % NUMPIXELS), pixels.Color(0, 0, 10));
    pixels.setPixelColor(NUMPIXELS-1 + ((snake_position_two - 2) % NUMPIXELS), pixels.Color(0, 0, 10));
    pixels.setPixelColor(NUMPIXELS-1 + ((snake_position_two - 3) % NUMPIXELS), pixels.Color(0, 0, 30));
    pixels.setPixelColor(NUMPIXELS-1 + ((snake_position_two - 4) % NUMPIXELS), pixels.Color(0, 0, 60));
    snake_position_two--;

    pixels.setPixelColor(snake_position % NUMPIXELS, pixels.Color(0, 0, 0));
    pixels.setPixelColor((snake_position + 1) % NUMPIXELS, pixels.Color(10, 0, 0));
    pixels.setPixelColor((snake_position + 2) % NUMPIXELS, pixels.Color(10, 0, 0));
    pixels.setPixelColor((snake_position + 3) % NUMPIXELS, pixels.Color(30, 0, 0));
    pixels.setPixelColor((snake_position + 4) % NUMPIXELS, pixels.Color(60, 0, 0));
    snake_position++;

    pixels.show();
    delay(100);
  }
}
