#include "main.h"


unsigned char ssd[MAX_SSD_CNT];
unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
unsigned int key_detected;
unsigned char flag=0;
State current_state = operational_mode;
static void init_config(void)
{
    init_digital_keypad();
    PEIE= 1;
    GIE = 1;
	init_external_interrupt();
    init_ssd_control();
    init_can();
   
}
void main(void)
{
    init_config();
    unsigned char key;
    
    while(1)
    {
        key=read_digital_keypad(STATE_CHANGE);
        if (key_detected)
        {
            key_detected = 0;
            if (flag)
            {
                current_state = config_mode;  
            }
            else
            {
                current_state = operational_mode;
            }
        }
        if (current_state == operational_mode)
        {
            operation_mode(key);
        }
        else if (current_state == config_mode)
        {
            configuration_mode(key);
        }
        else if(current_state==id_mode)
        {
             node_id_mode(key);
        }
        else if(current_state==stock_mode)
        {
             update_stock_mode(key);
        }
        
        display(ssd);
    }
    
    return;
}

