#include "Display.h"

Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);

Arduino_ILI9341 display = Arduino_ILI9341(&bus, TFT_RESET);

void initializeDisplay() {
    display.begin();
    display.setRotation(3);
    display.fillScreen(BLACK);
}

void cleanDisplay()
{
  display.fillScreen(BLACK);
}

void displayText(int x, int y, const char* text, uint16_t color) {
    display.setCursor(x, y);
    display.setTextColor(color);
    display.setTextSize(2);
    display.print(text);
}


void draw16bitRGB(int16_t x,int16_t y,const uint16_t * bitmap,int16_t w,int16_t h)
{
   display.draw16bitRGBBitmap(x, y, bitmap , w, h);
}
 


 // display.draw16bitRGBBitmap(0, 0, face_18 , 256, 256);//720 900
  
  //display.draw16bitRGBBitmap(0, 0, face_42 , 256, 256);//720 900
 // display.draw16bitRGBBitmap(0, 0, face_43 , 256, 256);//720 900
 // display.draw16bitRGBBitmap(0, 0, face_61 , 256, 256);//720 900
 // display.draw16bitRGBBitmap(0, 0, face_66 , 256, 256);//720 900

 //display.draw16bitRGBBitmap(0, 0, face_68 , 256, 256);//720 900

  //display.draw16bitRGBBitmap(0, 0, face_71 , 256, 256);//720 900
  //display.draw16bitRGBBitmap(0, 0, face_72 , 256, 256);//720 900