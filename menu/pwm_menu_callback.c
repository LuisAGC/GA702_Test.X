#include <xc.h>
#include <stdio.h>
#include "pwm_menu_callback.h"
#include "../i2c_lcd_dma.h"
#include "../i2c_lcd_dma_impl.h"
#include "MicroMenu.h"


char pwm_menu_buffer[21];

const char pwm_menu_text_array[2][21] = {
    "%cPWM Duty:   %05u",
    "%cPWM Period: %05u",
};

static inline void PWM_Draw_Helper(uint16_t currentPWMOption){
    char indicatorArray[] = {' ', ' '};
    indicatorArray[currentPWMOption] = '>';
    lcdBufferIndex = 1;
    LCD_Clear();
    
    uint16_t duty = OC1R;
    uint16_t period = OC1RS;
    
    sprintf(pwm_menu_buffer, pwm_menu_text_array[0], indicatorArray[0],duty );
    LCD_AppendGoto(0,0);
    LCD_AppendString(pwm_menu_buffer);
    
    sprintf(pwm_menu_buffer, pwm_menu_text_array[1], indicatorArray[1], period);
    LCD_AppendGoto(1,0);
    LCD_AppendString(pwm_menu_buffer);
    
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void PWM_Duty_Draw(void){
    PWM_Draw_Helper(0);
}

void PWM_Period_Draw(void){
    PWM_Draw_Helper(1);
}

void PWM_DutyInc(void){
    uint16_t duty = OC1R;
    duty++;
    OC1R = duty;
    MENU_RENDER;
}

void PWM_DutyDec(void){
    uint16_t duty = OC1R;
    duty--;
    OC1R = duty;
    MENU_RENDER;
}

void PWM_PeriodInc(void){
    uint16_t period = OC1RS;
    period++;
    OC1RS = period;
    MENU_RENDER;
}

void PWM_PeriodDec(void){
    uint16_t period = OC1RS;
    period--;
    OC1RS = period;
    MENU_RENDER;
}