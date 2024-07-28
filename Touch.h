#ifndef TOUCH_H
#define TOUCH_H

#define TOUCH_CS   33
#define TOUCH_IRQ  36

enum AppState {
    MAIN_MENU,
    SETTINGS_PAGE,
    SCHEDULE_PAGE,
    MANUAL_PAGE
};


#include <XPT2046_Touchscreen.h>

void initializeTouch(void );

int detectTouch(AppState* currentState);


#endif