#include "button_impl.h"
#include "led_impl.h"
#include "mcc_generated_files/pin_manager.h"

Led *currentLedInstance = &led1;
uint16_t currentLedNum = 1;

Button button1 = {
    .buttonLongPressCallbackFn = Button1_longPressCallback,
    .buttonShortPressCallbackFn = Button1_shortPressCallback,
    .buttonReleasedCallbackFn = Button1_releaseCallback,
    .currentStateFn = Button_Idle,
    .currentTicks = 0,
    .getButtonPhysicalStateCallbackFn = Button1_getButtonPhyState,
    .longPressTicks = 1500,
    .stabilizationTicks = 20
};

Button button2 = {
    .buttonLongPressCallbackFn = Button2_longPressCallback,
    .buttonShortPressCallbackFn = Button2_shortPressCallback,
    .buttonReleasedCallbackFn = Button2_releaseCallback,
    .currentStateFn = Button_Idle,
    .currentTicks = 0,
    .getButtonPhysicalStateCallbackFn = Button2_getButtonPhyState,
    .longPressTicks = 1500,
    .stabilizationTicks = 20
};

void Button1_shortPressCallback(void){
    Led_Ticker(currentLedInstance, LED_TOGGLE);
}

void Button1_longPressCallback(void){
    Led_Ticker(currentLedInstance, LED_PULSE);
}

void Button1_releaseCallback(void){
    
}

bool Button1_getButtonPhyState(void){
    if(IO_RB12_GetValue() == 1){
        return false;
    }
    else{
        return true;
    }
}

void Button2_shortPressCallback(void){
    switch(currentLedNum){
        case 1:
            currentLedInstance = &led2;
            currentLedNum = 2;
            break;
        case 2:
            currentLedInstance = &led3;
            currentLedNum = 3;
            break;
        case 3:
            currentLedInstance = &led4;
            currentLedNum = 4;
            break;
        case 4:
            currentLedInstance = &led1;
            currentLedNum = 1;
            break;
        default:
            currentLedInstance = &led1;
            currentLedNum = 1;
            break;
    }
}

void Button2_longPressCallback(void){
    switch(currentLedNum){
        case 1:
            currentLedInstance = &led4;
            currentLedNum = 4;
            break;
        case 2:
            currentLedInstance = &led1;
            currentLedNum = 1;
            break;
        case 3:
            currentLedInstance = &led2;
            currentLedNum = 2;
            break;
        case 4:
            currentLedInstance = &led3;
            currentLedNum = 3;
            break;
        default:
            currentLedInstance = &led1;
            currentLedNum = 1;
            break;
    }
}

void Button2_releaseCallback(void){

}

bool Button2_getButtonPhyState(void){
    if(IO_RB13_GetValue() == 1){
        return false;
    }
    else{
        return true;
    }
}