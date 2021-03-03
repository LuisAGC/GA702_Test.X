#ifndef BUTTON_IMPL_H
#define	BUTTON_IMPL_H

#include <stdint.h>
#include <stdbool.h>
#include "button.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    extern Button button1;
    extern Button button2;
    
    void Button1_shortPressCallback(void);
    void Button1_longPressCallback(void);
    void Button1_releaseCallback(void);
    bool Button1_getButtonPhyState(void);

    void Button2_shortPressCallback(void);
    void Button2_longPressCallback(void);
    void Button2_releaseCallback(void);
    bool Button2_getButtonPhyState(void);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* BUTTON_IMPL_H */

