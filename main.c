/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24FJ256GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#define SYS_FREQ 32000000L //Clock Frequency
#define FCY (SYS_FREQ/2) //Cycle Frequency
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <libpic30.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/oc1.h"
#include "mcc_generated_files/i2c1.h"
#include "led.h"
#include "button.h"
#include "led_impl.h"
#include "button_impl.h"
#include "at_command_parser.h"
#include "at_parser_impl.h"
#include "i2c_lcd_dma.h"
#include "i2c_lcd_dma_impl.h"


/*
                         Main application
 */

volatile bool TMR1_Overflowed = false;
uint16_t millis = 0;
uint32_t seconds = 0;
char textBuffer[21];
const char textTemplate[] = "%010lu";

void TMR1_OverflowHandler(void)
{
    TMR1_Overflowed = true;
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalDisable();
    TMR1_SetInterruptHandler(&TMR1_OverflowHandler);
    IEC1bits.MI2C1IE = 0;
    INTERRUPT_GlobalEnable();
    __delay_ms(50);
    Init_Leds();
    Init_Parser();
    LCD_Init();
    LCD_AppendGoto(0,0);
    LCD_AppendString("Hello World!!!");
    LCD_AppendGoto(1,0);
    LCD_AppendString("PIC24 On:");
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
    printf("SYSTEM STARTED: READY TO RECEIVE COMMANDS\r\n");
    while (1) {
        if(TMR1_Overflowed == true){
            TMR1_Overflowed = false;
            Led_Ticker(&led1, LED_TICK);
            Led_Ticker(&led2, LED_TICK);
            Led_Ticker(&led3, LED_TICK);
            Led_Ticker(&led4, LED_TICK);
            Button_Ticker(&button1);
            Button_Ticker(&button2);
            millis++;
        }
        if(UART1_IsRxReady()){
          AT_Ticker(&atCommandParserSingleton, UART1_Read());          
        }           
        if(millis > 999){
            millis = 0;
            lcdBufferIndex = 1;
            sprintf(textBuffer, textTemplate, seconds);
            seconds++;
            LCD_AppendGoto(2,0);
            LCD_AppendString(textBuffer);
            LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
        }
    }
    return 1;
}
/**
 End of File
*/

