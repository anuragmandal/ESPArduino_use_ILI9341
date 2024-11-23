#ifndef TOUCH_H
#define TOUCH_H

#define TOUCH_CS   33
#define TOUCH_IRQ  36
#include <XPT2046_Touchscreen.h>

// Define page event types
typedef enum {
  EVENT_NONE,
  EVENT_MAIN_MENU,
  EVENT_MANUAL_PAGE,
  EVENT_SCHEDULE_PAGE,
  EVENT_SETTINGS_PAGE,
} PageEvent;

// Define the possible states for the application
typedef enum {
  MAIN_MENU,      // Main menu screen
  MANUAL_PAGE,    // Manual control page
  SCHEDULE_PAGE,  // Schedule settings page
  SETTINGS_PAGE   // Settings page
} AppState;

// Declare a queue handle
extern QueueHandle_t touchEventQueue;

void initializeTouch(void );

int detectTouch(AppState* currentState);
void detectTouchTask(void *pvParameters);


#endif