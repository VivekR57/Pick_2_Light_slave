#include "main.h"
extern unsigned char digit[];
extern unsigned char ssd[MAX_SSD_CNT];
extern State current_state;

void node_id_mode(char key)
{
    static char field = 0;
    static int a = 176, b = 0, c = 0, d = 0;
    if (a == 176) 
    {
        a = read_internal_eeprom(0x00);
        b = read_internal_eeprom(0x01);
        c = read_internal_eeprom(0x02);
        d = read_internal_eeprom(0x03);
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
        write_internal_eeprom(0x00, a);
        write_internal_eeprom(0x01, b);
        write_internal_eeprom(0x02, c);
        write_internal_eeprom(0x03, d);
        current_state = operational_mode;
        return;
    }

    if (field == 0)
    {
        ssd[0] = digit[a] | DOT;
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