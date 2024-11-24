#include "Touch.h"

XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);



void initializeTouch(void )
{
    if (!ts.begin()) {
    Serial.println("\nTouchscreen not found!");
    while (1);
  }
  
}

void detectTouchTask(void *pvParameters)
{
  
  #if 1
  AppState currentState = *((AppState*)pvParameters);
  Serial.print("Current state= ");Serial.print(currentState );
  PageEvent event = EVENT_NONE;

  while (true) {
    
    if (ts.tirqTouched() && ts.touched()) {
      TS_Point p = ts.getPoint();
  
      p.x = map(p.x, 3800, 200, 0, 240);
      p.y = map(p.y, 200, 3800, 0, 320);
      Serial.print("X = "); Serial.print(p.x); Serial.print(", Y = "); Serial.println(p.y);
 
      if (currentState == MAIN_MENU) 
      {
        if (p.x >= 180 && p.x <= 220 && p.y >= 41 && p.y <= 66) {
            event = EVENT_MANUAL_PAGE;
            Serial.println("Mannual Page");
        } else if (p.x >= 180 && p.x <= 210 && p.y >= 140 && p.y <= 187) {
            event = EVENT_SCHEDULE_PAGE;
            Serial.println("SCHEDULE_PAGE");
        } else if (p.x >= 165 && p.x <= 225 && p.y >= 250 && p.y <= 309) {
            event = EVENT_SETTINGS_PAGE;
            Serial.println("SETTINGS_PAGE");
        }
      } 
      else if (currentState == SETTINGS_PAGE) 
      {
        if (p.x >= 0 && p.x <= 240 && p.y >= 0 && p.y <= 320) {
            event = EVENT_MAIN_MENU;
            Serial.println("MAIN_MENU");
        }
      }

    // Send the event to the queue if a valid event occurred
        if (event != EVENT_NONE) {
          xQueueSend(touchEventQueue, &event, portMAX_DELAY);
          event = EVENT_NONE;  // Reset event after sending
        }
    }
    
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  #endif
}

