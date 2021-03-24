#include <stdio.h>
#include "at_parser_impl.h"
#include "menu/ledstate_menu_callback.h"
#include "menu/MicroMenu.h"

void Init_Parser(void){
    atCommandParserSingleton.callbackFn = commandSuccessfullyParsed;
    atCommandParserSingleton.errorCallbackFn = commandError;
}

void commandChangeLedState(Led *ledInstance, uint16_t state){
    switch(state){
        case 0:
            printf("Off\r\n");
            Led_Ticker(ledInstance, LED_OFF);
            break;
        case 1:
            printf("On\r\n");
            Led_Ticker(ledInstance, LED_ON);
            break;
        case 2:
            printf("Pulsing\r\n");
            Led_Ticker(ledInstance, LED_PULSE);
            break;
        default:
            break;
    }
}

void commandLedState(ATCommand *command){
    switch(command->modifierIndex){
        case 0:
            switch(command->data[0]){
                case 1:
                    printf("Led 1 is now ");
                    led1CurrentState = command->data[1];
                    commandChangeLedState(&led1, command->data[1]);
                    break;
                case 2:
                    printf("Led 2 is now ");
                    led2CurrentState = command->data[1];
                    commandChangeLedState(&led2, command->data[1]);
                    break;
                case 3:
                    printf("Led 3 is now ");
                    led3CurrentState = command->data[1];
                    commandChangeLedState(&led3, command->data[1]);
                    break;
                case 4:
                    printf("Led 4 is now ");
                    led4CurrentState = command->data[1];
                    commandChangeLedState(&led4, command->data[1]);
                    break;
                case 5:
                    printf("All Leds are now:\r\n");
                    led1CurrentState = command->data[1];
                    led2CurrentState = command->data[1];
                    led3CurrentState = command->data[1];
                    led4CurrentState = command->data[1];
                    commandChangeLedState(&led1, command->data[1]);
                    commandChangeLedState(&led2, command->data[1]);
                    commandChangeLedState(&led3, command->data[1]);
                    commandChangeLedState(&led4, command->data[1]);
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        case 1:
            switch(command->data[0]){
                case 1:
                    printf("Led 1 is OK\r\n");
                    break;
                case 2:
                    printf("Led 2 is OK\r\n");
                    break;
                case 3:
                    printf("Led 3 is OK\r\n");
                    break;
                case 4:
                    printf("Led 4 is OK\r\n");
                    break;
                case 5:
                    printf("All Leds are OK\r\n");
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        default:
            break;
    }
    MENU_RENDER();
}

void commandChangeLedPulse(Led *ledInstance, uint16_t pulses, uint16_t pulseLow, uint16_t pulseHigh){
    ledInstance->pulsesAmount = pulses;
    ledInstance->pulseLowDurationTicks = pulseLow;
    ledInstance->pulseHighDurationTicks = pulseHigh;
}

void commandLedPulse(ATCommand *command){
    switch(command->modifierIndex){
        case 0:
            switch(command->data[0]){
                case 1:
                    printf("Led 1 pulse configuration changed\r\n");
                    printf("Pulses Amount: %d\r\n", command->data[1]);
                    printf("Ticks Low: %d\r\n", command->data[2]);
                    printf("Ticks High: %d\r\n", command->data[3]);
                    commandChangeLedPulse(&led1, command->data[1], command->data[2], command->data[3]);
                    break;
                case 2:
                    printf("Led 2 pulse configuration changed\r\n");                    
                    printf("Pulses Amount: %d\r\n", command->data[1]);
                    printf("Ticks Low: %d\r\n", command->data[2]);
                    printf("Ticks High: %d\r\n", command->data[3]);
                    commandChangeLedPulse(&led2, command->data[1], command->data[2], command->data[3]);
                    break;
                case 3:
                    printf("Led 3 pulse configuration changed\r\n");
                    printf("Pulses Amount: %d\r\n", command->data[1]);
                    printf("Ticks Low: %d\r\n", command->data[2]);
                    printf("Ticks High: %d\r\n", command->data[3]);
                    commandChangeLedPulse(&led3, command->data[1], command->data[2], command->data[3]);
                    break;
                case 4:
                    printf("Led 4 pulse configuration changed\r\n");
                    printf("Pulses Amount: %d\r\n", command->data[1]);
                    printf("Ticks Low: %d\r\n", command->data[2]);
                    printf("Ticks High: %d\r\n", command->data[3]);
                    commandChangeLedPulse(&led4, command->data[1], command->data[2], command->data[3]);
                    break;    
                case 5:
                    printf("All Leds pulse configuration changed\r\n");
                    printf("Pulses Amount: %d\r\n", command->data[1]);
                    printf("Ticks Low: %d\r\n", command->data[2]);
                    printf("Ticks High: %d\r\n", command->data[3]);
                    commandChangeLedPulse(&led1, command->data[1], command->data[2], command->data[3]);
                    commandChangeLedPulse(&led2, command->data[1], command->data[2], command->data[3]);
                    commandChangeLedPulse(&led3, command->data[1], command->data[2], command->data[3]);
                    commandChangeLedPulse(&led4, command->data[1], command->data[2], command->data[3]);
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        case 1:
            switch(command->data[0]){
                case 1:
                    printf("Led 1 is OK\r\n");
                    break;
                case 2:
                    printf("Led 2 is OK\r\n");
                    break;
                case 3:
                    printf("Led 3 is OK\r\n");
                    break;
                case 4:
                    printf("Led 4 is OK\r\n");
                    break;
                case 5:
                    printf("All Leds are OK\r\n");
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        default:
            break;
    }
    MENU_RENDER();
}

void commandPwmPeriod(ATCommand *command){
    uint16_t OC1_secondaryValue = OC1RS;
    switch(command->modifierIndex){
        case 0:
            OC1_SecondaryValueSet(command->data[0]);
            printf("PWM Period Set to %u\r\n",command->data[0]);
            break;
        case 1:
            printf("PWM Period is set to %u\r\n", OC1_secondaryValue);
            break;
    }
    MENU_RENDER();
}

void commandPwmDuty(ATCommand *command){
    uint16_t OC1_primaryValue = OC1R;
    switch(command->modifierIndex){
        case 0:
            OC1_PrimaryValueSet(command->data[0]);
            printf("PWM Duty Set to %u\r\n",command->data[0]);
            break;
        case 1:
            printf("PWM Duty is set to %u\r\n", OC1_primaryValue);
            break;
    }
    MENU_RENDER();
}

void commandSuccessfullyParsed(ATCommand *command){
    printf("OK: \r\n");
    switch(command->commandIndex){
        case 0:
            commandLedState(command);
            break;
        case 1:
            commandLedPulse(command);
            break;
        case 2:
            commandPwmPeriod(command);
            break;
        case 3:
            commandPwmDuty(command);
            break;
        default:
            break;
    }
}

void commandError(){
    printf("Invalid Command\r\n");
}