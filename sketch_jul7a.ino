#include "SensorSystem.h"
#include "Display.h"
#include "Touch.h"
#include <Arduino.h>

// Declare a queue handle
QueueHandle_t touchEventQueue;


//AppState currentState = MAIN_MENU;








 
void setup(void)
{
 
  Serial.begin(115200);
 
  initializeDisplay();
  initializeTouch();

  SensorSystem sensor;

  

  sensor.setTemperature(25);
  sensor.setWaterLevel(70);
  sensor.setMoisture(45);

  sensor.displayData();
   draw16bitRGB(10, 250, mannual, 70, 63);//mannual button
   draw16bitRGB(90, 250, schedule, 65, 60);//schedule button
   draw16bitRGB(165, 250, settings, 60, 59);//settings button

  touchEventQueue = xQueueCreate(10, sizeof(PageEvent));

  AppState currentState = MAIN_MENU;

  xTaskCreate(detectTouchTask, "Touch Task", 2048, &currentState,1,NULL);

  xTaskCreate(pageEventHandlerTask, "Page Handler Task", 2048, &currentState, 1, NULL );
  
  vTaskStartScheduler();

}
 
void loop() {




#if 0
  if(detectTouch(&currentState))
  {
   
    if(currentState == MAIN_MENU)
    {
        SensorSystem sensor;
        cleanDisplay();
        sensor.setTemperature(25);
        sensor.setWaterLevel(70);
        sensor.setMoisture(45);
        sensor.displayData();
        draw16bitRGB(10, 250, mannual , 70, 63);//720 900
        draw16bitRGB(90, 250, schedule , 65, 60);//720 900
        draw16bitRGB(165, 250,settings , 60, 59);//720 900 
    }

  }
   #endif
  //Serial.print("Raw X = "); Serial.print(p.x); Serial.print(", Raw Y = "); Serial.print(p.y); Serial.print(", Z = "); Serial.println(p.z);
  delay(5);
 
}

