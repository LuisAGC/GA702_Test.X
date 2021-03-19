#include "led_impl.h"
#include "mcc_generated_files/pin_manager.h"

Led led1 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led1_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 125,
    .pulseLowDurationTicks = 125,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led2 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led2_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 250,
    .pulseLowDurationTicks = 250,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led3 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led3_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 500,
    .pulseLowDurationTicks = 500,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led4 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led4_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 1000,
    .pulseLowDurationTicks = 1000,
    .pulsesAmount = LED_PULSE_FOREVER
};

void Init_Leds(void){
    Led_Ticker(&led1, LED_OFF);
    Led_Ticker(&led2, LED_OFF);
    Led_Ticker(&led3, LED_OFF);
    Led_Ticker(&led4, LED_OFF);
}

void Led1_Callback(bool phyState){
    if(phyState == true){
        LED_1_SetHigh();
    }
    else{
        LED_1_SetLow();
    }
}

void Led2_Callback(bool phyState){
    if(phyState == true){
        LED_2_SetHigh();
    }
    else{
        LED_2_SetLow();
    }
}

void Led3_Callback(bool phyState){
    if(phyState == true){
        LED_3_SetHigh();
    }
    else{
        LED_3_SetLow();
    }
}

void Led4_Callback(bool phyState){
    if(phyState == true){
        LED_4_SetHigh();
    }
    else{
        LED_4_SetLow();
    }
}

