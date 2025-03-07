#include "main.h"
extern unsigned char digit[];
extern unsigned char ssd[MAX_SSD_CNT];
extern State current_state;
//static int temp_u_st;
void update_stock_mode(char key)
{
    static char field = 0;
    static int a = 175, b = 0, c = 0, d = 0;
    if (a == 175) 
    {
        a = read_internal_eeprom(0x04);
        b = read_internal_eeprom(0x05);
        c = read_internal_eeprom(0x06);
        d = read_internal_eeprom(0x07);
    }
    
    if (key == SWITCH1)
    {
        if (field == 0)
        {
            if (++a > 9)
            {
                a = 0;
            }
        }
        if (field == 1)
        {
            if (++b > 9)
            {
                b = 0;
            }
        }
        if (field == 2)
        {
            if (++c > 9)
            {
                c = 0;
            }
        }
        if (field == 3)
        {
            if (++d > 9)
            {
                d = 0;
            }
        }
    }
    
    if (key == SWITCH2)
    {
        if (++field > 3)
        {
            field = 0;
        }
    }
    
    if (key == SWITCH3)
    {
        write_internal_eeprom(0x04, a);
        write_internal_eeprom(0x05, b);
        write_internal_eeprom(0x06, c);
        write_internal_eeprom(0x07, d);
        current_state = operational_mode;
        can_transmit();
        return;
    }
    
   // temp_u_st = (a * 1000) + (b * 100) + (c * 10) + d;
    

    if (field == 0)
    {
        ssd[0]=digit[a] | DOT;
        ssd[1] = digit[b];
        ssd[2] = digit[c];
        ssd[3] = digit[d];
    }
    else if (field == 1)
    {
        ssd[0] = digit[a];
        ssd[1] = digit[b] | DOT; 
        ssd[2] = digit[c];
        ssd[3] = digit[d];
    }
    else if (field == 2)
    {
        ssd[0] = digit[a];
        ssd[1] = digit[b];
        ssd[2] = digit[c] | DOT;
        ssd[3] = digit[d];
    }
    else if (field == 3)
    {
        ssd[0] = digit[a];
        ssd[1] = digit[b];
        ssd[2] = digit[c];
        ssd[3] = digit[d] | DOT;
    }
}