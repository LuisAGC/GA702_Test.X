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
#include "menu/MicroMenu.h"


/*
                         Main application
 */

volatile bool TMR1_Overflowed = false;
uint16_t millisMenuCallback = 0;

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
    __delay_ms(100);
    LCD_Init();
    LCD_SendDMAData(lcdBuffer, lcdBufferIndex, 0x40);
    __delay_ms(100);
    Init_Leds();
    Init_Parser();
    Init_Buttons();
    OC1_SecondaryValueSet(0xFFFF);
    OC1_PrimaryValueSet(0x0001);
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
            Button_Ticker(&button3);
            millisMenuCallback++;
        }
        
        if(millisMenuCallback > 200){
            millisMenuCallback = 0;
            if(button1_longPressed == true){
                MENU_SELECT();
            }
            if(button2_longPressed == true){
                MENU_ENTER();
            }
        }
        
        if(UART1_IsRxReady()){
          AT_Ticker(&atCommandParserSingleton, UART1_Read());          
        }           
    }
    return 1;
}
/**
 End of File
*/

