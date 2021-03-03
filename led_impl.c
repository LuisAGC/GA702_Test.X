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
    Led_Ticker(&led1, LED_PULSE);
    Led_Ticker(&led2, LED_PULSE);
    Led_Ticker(&led3, LED_PULSE);
    Led_Ticker(&led4, LED_PULSE);
}

void Led1_Callback(bool phyState){
    if(phyState == true){
        IO_RB6_SetHigh();
    }
    else{
        IO_RB6_SetLow();
    }
}

void Led2_Callback(bool phyState){
    if(phyState == true){
        IO_RB7_SetHigh();
    }
    else{
        IO_RB7_SetLow();
    }
}

void Led3_Callback(bool phyState){
    if(phyState == true){
        IO_RB8_SetHigh();
    }
    else{
        IO_RB8_SetLow();
    }
}

void Led4_Callback(bool phyState){
    if(phyState == true){
        IO_RB9_SetHigh();
    }
    else{
        IO_RB9_SetLow();
    }
}

