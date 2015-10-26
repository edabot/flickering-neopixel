#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9
#define NUM_LEDS    16


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


int ledLevel[NUM_LEDS];
int ledBrightness[] = {0,4,8,9,50,100,150,200,230,240};
int ledBrightnessG[] = {0,0,0,0,10,20,70,100,230,240};

void setup() {
  for(int i;i<NUM_LEDS;i++){
    ledLevel[i]=0;
  }
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  colortwinkles();
  strip.show();
}


void colortwinkles()
{
//Lowering brightness of each lit LED
  for (int i=0;i<NUM_LEDS;i++){
    strip.setPixelColor(i,ledBrightness[ledLevel[i]],ledBrightnessG[ledLevel[i]],0);
    if(ledLevel[i]>0){
      ledLevel[i]--; 
    }
  }

  int newLED = random(NUM_LEDS);
  int delayNess = random(50,150);
  //setting a new random LED at full brightness if it's off
  
  if (ledLevel[newLED]==0){
    ledLevel[newLED]=random[5,9];
  }

  delay(delayNess);
}


