The project shows how to display the 16bitRGBBitmap images and sensor values to the ILI9341 display. Now it will only display the front end menu page no backend work done!
It has some commented code in Display.cpp as of now to show emojis reaction for further explore.

Use hardware:

ESP32 ESP WROOM-32

LCD display ILI9341

Use dependencies libraries:

ESP32 version : 3.0.3

GFX Library for Arduino v1.4.7

XPT2046_Touchscreen by Paul Stoffregen v1.4

-----------------------------------------
Pint outs with respect to ESP WROOM-32
-----------------------------------------
LCD  ILI9341   |   ESP32 GPIO
-----------------------------------------
TFT_SCK                                18

TFT_MOSI                               23

TFT_MISO                               19

TFT_CS                                 22

TFT_DC                                 21

TFT_RESET          17

-----------------------------------------
Touch XPT2046  |   ESP32 GPIO
-----------------------------------------
TOUCH_CS                              33

TOUCH_IRQ                             36

TFT_SCK                               18

TFT_MOSI                              23

TFT_MISO           19
