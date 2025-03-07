#include "main.h"

unsigned char node_id[] = {0xA8, 0x08, 0x80, 0xE9};
unsigned char update_stock [] = {0xE5, 0x08, 0x6E, 0xCC};
extern unsigned char ssd[MAX_SSD_CNT];
extern State current_state;

void configuration_mode(char key)
{
    static char mode_flag = 0;
    static char mode_selected = 0;
    if (mode_selected == 0) 
    {
        if (key == SWITCH3) 
        {
            mode_flag = !mode_flag;
        }
        if (key == SWITCH2) 
        {
            mode_selected = 1;
            if (mode_flag == 0) 
            {

                current_state = id_mode;
            }
            else 
            {
                current_state = stock_mode;
            }
            mode_selected=0;
            return;
        }
    }
    if (mode_flag == 0) 
    {
        ssd[0] = node_id[0];
        ssd[1] = node_id[1];
        ssd[2] = node_id[2];
        ssd[3] = node_id[3];
    }
    if (mode_flag == 1)
    {
        ssd[0] = update_stock[0];
        ssd[1] = update_stock[1];
        ssd[2] = update_stock[2];
        ssd[3] = update_stock[3];
    }
    display(ssd);
}