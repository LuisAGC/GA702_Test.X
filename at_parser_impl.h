#ifndef AT_PARSER_IMPL_H
#define	AT_PARSER_IMPL_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "at_command_parser.h"
#include "led.h"
#include "led_impl.h"
#include "mcc_generated_files/oc1.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void commandChangeLedState(Led *ledInstance, uint16_t state);
    void commandLedState(ATCommand *command);
    void commandChangeLedPulse(Led *ledInstance, uint16_t pulses, uint16_t pulseLow, uint16_t pulseHigh);
    void commandLedPulse(ATCommand *command);
    void commandPwmPeriod(ATCommand *command);
    void commandPwmDuty(ATCommand *command);
    void commandSuccessfullyParsed(ATCommand *command);
    void commandError(void);
    
    void Init_Parser(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* AT_PARSER_IMPL_H */

