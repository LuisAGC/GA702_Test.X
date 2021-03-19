#ifndef MENU_IMPL_H
#define	MENU_IMPL_H

#include "MicroMenu.h"
#include "main_menu_callback.h"
#include "ledstate_menu_callback.h"
#include "ledpulse_menu_callback.h"
#include "pwm_menu_callback.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    //Main menu items, callbacks are in main_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(MainMenu_LedState,    MainMenu_LedPulse,  MainMenu_PWM,       NULL_MENU, LedState_1,  NULL, NULL, MainMenu_LedState_Draw);
    MENU_ITEM(MainMenu_LedPulse,    MainMenu_PWM,       MainMenu_LedState,  NULL_MENU, LedPulse_1,  NULL, NULL, MainMenu_LedPulse_Draw);
    MENU_ITEM(MainMenu_PWM,         MainMenu_LedState,  MainMenu_LedPulse,  NULL_MENU, PWM_Duty,    NULL, NULL, MainMenu_PWM_Draw);
    
    //Led state menu items, callbacks are in ledstate_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(LedState_1,       LedState_2,     LedState_4,     MainMenu_LedState,  LedState_1_Sub, NULL, NULL,     LedState_1_Draw);
    MENU_ITEM(LedState_2,       LedState_3,     LedState_1,     MainMenu_LedState,  LedState_2_Sub, NULL, NULL,     LedState_2_Draw);
    MENU_ITEM(LedState_3,       LedState_4,     LedState_2,     MainMenu_LedState,  LedState_3_Sub, NULL, NULL,     LedState_3_Draw);
    MENU_ITEM(LedState_4,       LedState_1,     LedState_3,     MainMenu_LedState,  LedState_4_Sub, NULL, NULL,     LedState_4_Draw);
    
    MENU_ITEM(LedState_1_Sub,   NULL_MENU,      NULL_MENU,      LedState_1,         NULL_MENU,      NULL, NULL,     LedState_1_Callback);
    MENU_ITEM(LedState_2_Sub,   NULL_MENU,      NULL_MENU,      LedState_2,         NULL_MENU,      NULL, NULL,     LedState_2_Callback);
    MENU_ITEM(LedState_3_Sub,   NULL_MENU,      NULL_MENU,      LedState_3,         NULL_MENU,      NULL, NULL,     LedState_3_Callback);
    MENU_ITEM(LedState_4_Sub,   NULL_MENU,      NULL_MENU,      LedState_4,         NULL_MENU,      NULL, NULL,     LedState_4_Callback);
    
    //Led pulse menu items, callbacks are in ledpulse_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(LedPulse_1, LedPulse_2, LedPulse_4, MainMenu_LedPulse, LedPulse_1_PulseHigh, NULL, NULL, LedPulse_1_Draw);
    MENU_ITEM(LedPulse_2, LedPulse_3, LedPulse_1, MainMenu_LedPulse, LedPulse_2_PulseHigh, NULL, NULL, LedPulse_2_Draw);
    MENU_ITEM(LedPulse_3, LedPulse_4, LedPulse_2, MainMenu_LedPulse, LedPulse_3_PulseHigh, NULL, NULL, LedPulse_3_Draw);
    MENU_ITEM(LedPulse_4, LedPulse_1, LedPulse_3, MainMenu_LedPulse, LedPulse_4_PulseHigh, NULL, NULL, LedPulse_4_Draw);
    
    MENU_ITEM(LedPulse_1_PulseHigh, LedPulse_1_PulseLow,    LedPulse_1_Pulses,      LedPulse_1, NULL_MENU, LedPulse_1_PulseHighInc, LedPulse_1_PulseHighDec,    LedPulse_1_PulseHigh_Draw);
    MENU_ITEM(LedPulse_1_PulseLow,  LedPulse_1_Pulses,      LedPulse_1_PulseHigh,   LedPulse_1, NULL_MENU, LedPulse_1_PulseLowInc,  LedPulse_1_PulseLowDec,     LedPulse_1_PulseLow_Draw);
    MENU_ITEM(LedPulse_1_Pulses,    LedPulse_1_PulseHigh,   LedPulse_1_PulseLow,    LedPulse_1, NULL_MENU, LedPulse_1_PulsesInc,    LedPulse_1_PulsesDec,       LedPulse_1_Pulses_Draw);
    
    MENU_ITEM(LedPulse_2_PulseHigh, LedPulse_2_PulseLow,    LedPulse_2_Pulses,      LedPulse_2, NULL_MENU, LedPulse_2_PulseHighInc, LedPulse_2_PulseHighDec,    LedPulse_2_PulseHigh_Draw);
    MENU_ITEM(LedPulse_2_PulseLow,  LedPulse_2_Pulses,      LedPulse_2_PulseHigh,   LedPulse_2, NULL_MENU, LedPulse_2_PulseLowInc,  LedPulse_2_PulseLowDec,     LedPulse_2_PulseLow_Draw);
    MENU_ITEM(LedPulse_2_Pulses,    LedPulse_2_PulseHigh,   LedPulse_2_PulseLow,    LedPulse_2, NULL_MENU, LedPulse_2_PulsesInc,    LedPulse_2_PulsesDec,       LedPulse_2_Pulses_Draw);
    
    MENU_ITEM(LedPulse_3_PulseHigh, LedPulse_3_PulseLow,    LedPulse_3_Pulses,      LedPulse_3, NULL_MENU, LedPulse_3_PulseHighInc, LedPulse_3_PulseHighDec,    LedPulse_3_PulseHigh_Draw);
    MENU_ITEM(LedPulse_3_PulseLow,  LedPulse_3_Pulses,      LedPulse_3_PulseHigh,   LedPulse_3, NULL_MENU, LedPulse_3_PulseLowInc,  LedPulse_3_PulseLowDec,     LedPulse_3_PulseLow_Draw);
    MENU_ITEM(LedPulse_3_Pulses,    LedPulse_3_PulseHigh,   LedPulse_3_PulseLow,    LedPulse_3, NULL_MENU, LedPulse_3_PulsesInc,    LedPulse_3_PulsesDec,       LedPulse_3_Pulses_Draw);
    
    MENU_ITEM(LedPulse_4_PulseHigh, LedPulse_4_PulseLow,    LedPulse_4_Pulses,      LedPulse_4, NULL_MENU, LedPulse_4_PulseHighInc, LedPulse_4_PulseHighDec,    LedPulse_4_PulseHigh_Draw);
    MENU_ITEM(LedPulse_4_PulseLow,  LedPulse_4_Pulses,      LedPulse_4_PulseHigh,   LedPulse_4, NULL_MENU, LedPulse_4_PulseLowInc,  LedPulse_4_PulseLowDec,     LedPulse_4_PulseLow_Draw);
    MENU_ITEM(LedPulse_4_Pulses,    LedPulse_4_PulseHigh,   LedPulse_4_PulseLow,    LedPulse_4, NULL_MENU, LedPulse_4_PulsesInc,    LedPulse_4_PulsesDec,       LedPulse_4_Pulses_Draw);
    
    //PWM menu items, callbacks are in pwm_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(PWM_Duty,     PWM_Period, PWM_Period, MainMenu_PWM,  NULL_MENU, PWM_DutyInc,      PWM_DutyDec,    PWM_Duty_Draw);
    MENU_ITEM(PWM_Period,   PWM_Duty,   PWM_Duty,   MainMenu_PWM,  NULL_MENU, PWM_PeriodInc,    PWM_PeriodDec,  PWM_Period_Draw);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MENU_IMPL_H */

