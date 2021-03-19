#include "button_impl.h"
#include "led_impl.h"
#include "menu/menu_impl.h"
#include "mcc_generated_files/pin_manager.h"

Button button1 = {
    .buttonLongPressCallbackFn = Button1_longPressCallback,
    .buttonShortPressCallbackFn = Button1_shortPressCallback,
    .buttonReleasedCallbackFn = Button1_releaseCallback,
    .currentStateFn = Button_Idle,
    .currentTicks = 0,
    .getButtonPhysicalStateCallbackFn = Button1_getButtonPhyState,
    .longPressTicks = 800,
    .stabilizationTicks = 10
};

Button button2 = {
    .buttonLongPressCallbackFn = Button2_longPressCallback,
    .buttonShortPressCallbackFn = Button2_shortPressCallback,
    .buttonReleasedCallbackFn = Button2_releaseCallback,
    .currentStateFn = Button_Idle,
    .currentTicks = 0,
    .getButtonPhysicalStateCallbackFn = Button2_getButtonPhyState,
    .longPressTicks = 800,
    .stabilizationTicks = 10
};

Button button3 = {
    .buttonLongPressCallbackFn = Button3_longPressCallback,
    .buttonShortPressCallbackFn = Button3_shortPressCallback,
    .buttonReleasedCallbackFn = Button3_releaseCallback,
    .currentStateFn = Button_Idle,
    .currentTicks = 0,
    .getButtonPhysicalStateCallbackFn = Button3_getButtonPhyState,
    .longPressTicks = 800,
    .stabilizationTicks = 10
};

bool button1_longPressed = false;
bool button2_longPressed = false;

void Init_Buttons(){
    Menu_Navigate(&MainMenu_LedState);
}

void Button1_shortPressCallback(void){
    Menu_Navigate(MENU_PREVIOUS);
}

void Button1_longPressCallback(void){
    button1_longPressed = true;
}

void Button1_releaseCallback(void){
    button1_longPressed = false;
}

bool Button1_getButtonPhyState(void){
    if(BUTTON_1_GetValue() == 1){
        return true;
    }
    else{
        return false;
    }
}

void Button2_shortPressCallback(void){
    Menu_Navigate(MENU_NEXT);
}

void Button2_longPressCallback(void){
    button2_longPressed = true;
}

void Button2_releaseCallback(void){
    button2_longPressed = false;;
}

bool Button2_getButtonPhyState(void){
    if(BUTTON_2_GetValue() == 1){
        return true;
    }
    else{
        return false;
    }
}

void Button3_shortPressCallback(void){
    Menu_Navigate(MENU_CHILD);
}

void Button3_longPressCallback(void){
    Menu_Navigate(MENU_PARENT);
}

void Button3_releaseCallback(void){
    
}

bool Button3_getButtonPhyState(void){
    if(BUTTON_3_GetValue() == 1){
        return true;
    }
    else{
        return false;
    }
}