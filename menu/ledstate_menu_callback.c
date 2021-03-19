#include <stdio.h>

#include "ledstate_menu_callback.h"
#include "../i2c_lcd_dma.h"
#include "../i2c_lcd_dma_impl.h"
#include "../led_impl.h"
#include "MicroMenu.h"

const char ledStateMenuText1[] = "%cLed %d state: ";
char ledStateMenuText2[] = "OFF";
char ledStateMenuText3[] = "ON";
char ledStateMenuText4[] = "PULSE";
char ledStateMenuBuffer[22];

uint16_t led1CurrentState = 0;
uint16_t led2CurrentState = 0;
uint16_t led3CurrentState = 0;
uint16_t led4CurrentState = 0;

void LedState_Draw_Helper(uint16_t ledCurrentState){
    switch(ledCurrentState){
        case 0:
            LCD_AppendString(ledStateMenuText2);
            break;
        case 1:
            LCD_AppendString(ledStateMenuText3);
            break;
        case 2:
            LCD_AppendString(ledStateMenuText4);
            break;
        default:
            break;
    }
}

void LedState_1_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', 1);
    LCD_AppendGoto(0,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 2);
    LCD_AppendGoto(1,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 3);
    LCD_AppendGoto(2,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 4);
    LCD_AppendGoto(3,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
    
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void LedState_2_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    LCD_AppendGoto(0,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', 2);
    LCD_AppendGoto(1,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 3);
    LCD_AppendGoto(2,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 4);
    LCD_AppendGoto(3,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
    
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void LedState_3_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    LCD_AppendGoto(0,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 2);
    LCD_AppendGoto(1,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', 3);
    LCD_AppendGoto(2,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 4);
    LCD_AppendGoto(3,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
    
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void LedState_4_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    LCD_AppendGoto(0,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 2);
    LCD_AppendGoto(1,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 3);
    LCD_AppendGoto(2,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', 4);
    LCD_AppendGoto(3,0);
    LCD_AppendString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
    
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}
    

void LedState_1_Callback(void){
    switch(led1CurrentState){
        case 0:
            Led_Ticker(&led1, LED_ON);
            led1CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led1, LED_PULSE);
            led1CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led1, LED_OFF);
            led1CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_2_Callback(void){
    switch(led2CurrentState){
        case 0:
            Led_Ticker(&led2, LED_ON);
            led2CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led2, LED_PULSE);
            led2CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led2, LED_OFF);
            led2CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_3_Callback(void){
    switch(led3CurrentState){
        case 0:
            Led_Ticker(&led3, LED_ON);
            led3CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led3, LED_PULSE);
            led3CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led3, LED_OFF);
            led3CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_4_Callback(void){
    switch(led4CurrentState){
        case 0:
            Led_Ticker(&led4, LED_ON);
            led4CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led4, LED_PULSE);
            led4CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led4, LED_OFF);
            led4CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

