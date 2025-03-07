
#ifndef MAIN_H
#define	MAIN_H


#include <xc.h>
#include "digital_keypad.h"
#include "external_interrupt.h"
#include "ssd.h"
#include "eeprom.h"
#include "can.h"



#define _XTAL_FREQ 20000000

/* Defines the data */
#define TRUE			1
#define FALSE			0


typedef enum
{
    operational_mode,
            config_mode,
            id_mode,
            stock_mode
}State;

void configuration_mode(char key);
void operation_mode(char key);
void node_id_mode(char key);
void update_stock_mode(char key);


#endif	/* MAIN_H */

