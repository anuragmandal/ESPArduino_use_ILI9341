#ifndef DISPLAY_H
#define DISPLAY_H


#include <Arduino_GFX_Library.h>


#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     22
#define TFT_DC     21
#define TFT_RESET  17



extern Arduino_ILI9341 display;

void initializeDisplay();
void displayText(int x, int y, const char* text,uint16_t color);
void draw16bitRGB(int16_t x,int16_t y,const uint16_t * bitmap,int16_t w,int16_t h);
void cleanDisplay();

#endif

//Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);

  //display  = Arduino_ILI9341(&bus, TFT_RESET);

