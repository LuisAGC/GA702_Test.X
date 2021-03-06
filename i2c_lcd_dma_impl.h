#ifndef I2C_LCD_DMA_IMPL_H
#define	I2C_LCD_DMA_IMPL_H

#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void LCD_SendDMAData(uint8_t *data, uint16_t size, uint8_t i2cAddress);
    bool LCD_IsDMASending(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* I2C_LCD_DMA_IMPL_H */

