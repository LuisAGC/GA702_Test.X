#include <p24FJ256GA702.h>

#include "i2c_lcd_dma_impl.h"
#include "mcc_generated_files/dma.h"

bool isDmaSending = false;

void DMA_Channel0_CallBack(void){
    isDmaSending = false;
    I2C1CON1bits.PEN = 1;
}

bool LCD_IsDMASending(void){
    return isDmaSending;
}

void LCD_SendDMAData(uint8_t *data, uint16_t size, uint8_t i2cAddress){
    isDmaSending = true;
    *data=i2cAddress;
    DMA_SourceAddressSet(DMA_CHANNEL_0, (uint16_t)data);
    DMA_TransferCountSet(DMA_CHANNEL_0, size);
    DMA_ChannelEnable(DMA_CHANNEL_0);
    I2C1CON1bits.SEN = 1;
    
}