# flickering-neopixel

Arduino sketch for twinkling Adafruit's NeoPixel LEDs.

Each loop randomly picks one LED to set to become bright if it isn't already lit.
All lit LEDs fade with each loop.

Fade pattern for each LED is set with arrays at beginning of sketch.
