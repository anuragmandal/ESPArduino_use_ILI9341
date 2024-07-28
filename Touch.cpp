#include "Touch.h"

XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);



void initializeTouch(void )
{
    if (!ts.begin()) {
    Serial.println("\nTouchscreen not found!");
    while (1);
  }
  
}


int detectTouch(AppState* currentState)
{
  if (ts.tirqTouched() && ts.touched()) {
    TS_Point p = ts.getPoint();
 
    p.x = map(p.x, 3800, 200, 0, 240);
    p.y = map(p.y, 200, 3800, 0, 320);
    Serial.print("X = "); Serial.print(p.x); Serial.print(", Y = "); Serial.println(p.y);
    if (*currentState == MAIN_MENU) 
    {
      if (p.x >= 10 && p.x <= 80 && p.y >= 250 && p.y <= 313) {
          *currentState = MANUAL_PAGE;
      } else if (p.x >= 90 && p.x <= 155 && p.y >= 250 && p.y <= 310) {
          *currentState = SCHEDULE_PAGE;
      } else if (p.x >= 165 && p.x <= 225 && p.y >= 250 && p.y <= 309) {
          *currentState = SETTINGS_PAGE;
      }
    } 
    else if (*currentState == SETTINGS_PAGE) 
    {
      if (p.x >= 0 && p.x <= 240 && p.y >= 0 && p.y <= 320) {
          *currentState = MAIN_MENU;
      }
    }

    return 1;
  }
  return 0;
}

