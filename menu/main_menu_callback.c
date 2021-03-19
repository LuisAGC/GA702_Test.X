#include "main_menu_callback.h"
#include "../i2c_lcd_dma.h"
#include "../i2c_lcd_dma_impl.h"

char mainMenuText_1[] = "Led state config";
char mainMenuText_2[] = "Led pulse config";
char mainMenuText_3[] = "PWM config";

void MainMenu_LedState_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    LCD_AppendGoto(0,0);
    LCD_AppendChar('>');
    LCD_AppendString(mainMenuText_1);
    LCD_AppendGoto(1,1);
    LCD_AppendString(mainMenuText_2);
    LCD_AppendGoto(2,1);
    LCD_AppendString(mainMenuText_3);
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void MainMenu_LedPulse_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    LCD_AppendGoto(0,1);
    LCD_AppendString(mainMenuText_1);
    LCD_AppendGoto(1,0);
    LCD_AppendChar('>');
    LCD_AppendString(mainMenuText_2);
    LCD_AppendGoto(2,1);
    LCD_AppendString(mainMenuText_3);
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}

void MainMenu_PWM_Draw(void){
    lcdBufferIndex = 1;
    LCD_Clear();
    LCD_AppendGoto(0,1);
    LCD_AppendString(mainMenuText_1);
    LCD_AppendGoto(1,1);
    LCD_AppendString(mainMenuText_2);
    LCD_AppendGoto(2,0);
    LCD_AppendChar('>');
    LCD_AppendString(mainMenuText_3);
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
}