#ifndef LED_IMPL_H
#define	LED_IMPL_H

#include <stdint.h>
#include <stdbool.h>
#include "led.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    extern Led led1;
    extern Led led2;
    extern Led led3;
    extern Led led4;
    
    void Init_Leds(void);

    void Led1_Callback(bool phyState);
    void Led2_Callback(bool phyState);
    void Led3_Callback(bool phyState);
    void Led4_Callback(bool phyState);
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LED_IMPL_H */

