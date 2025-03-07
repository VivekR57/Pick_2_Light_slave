#include "main.h"

unsigned char ssd[MAX_SSD_CNT];
extern unsigned char digit[];

static int can_n_id; 
static int n_id;

static int can_u_st ;
static char flag = 0;
unsigned int  delay=0;

void operation_mode(char key)
{
    unsigned char key1;
    if (flag == 0)
    {  
        ssd[0] = 0;
        ssd[1] = 0;
        ssd[2] = 0;
        ssd[3] = 0;
        display(ssd);

        if (can_receive())
        {
            can_n_id = ((can_payload[D0] - '0') * 1000) +
                       ((can_payload[D1] - '0') * 100) +
                       ((can_payload[D2] - '0') * 10) +
                       (can_payload[D3] - '0');
            n_id = (read_internal_eeprom(0x00) * 1000) +
                   (read_internal_eeprom(0x01) * 100) +
                   (read_internal_eeprom(0x02) * 10) +
                   (read_internal_eeprom(0x03));

            if (can_n_id == n_id)
            {
                flag = 1;
                can_u_st = ((can_payload[D4] - '0') * 1000) +
                   ((can_payload[D5] - '0') * 100) +
                   ((can_payload[D6] - '0') * 10) +
                   (can_payload[D7] - '0'); 
            }
        }
    }
    if (flag == 1)
    { 
        key1=read_digital_keypad(LEVEL);
        
        
        if(key1==SWITCH1)
        {
            if(delay++>50)
            {
                delay =0;
                if(++can_u_st>9999)
                {
                    can_u_st=0;
                }
            }
            
        }
        
        if(key1==SWITCH2)
        {
            if(delay++>50)
            {
                delay =0;
                if(--can_u_st<0)
                {
                    can_u_st=9999;
                }
            }
        }     
        if(key==SWITCH3)
        {
            write_internal_eeprom(0x04, (can_u_st/1000)%10);
            write_internal_eeprom(0x05, (can_u_st/100)%10);
            write_internal_eeprom(0x06, (can_u_st/10)%10);
            write_internal_eeprom(0x07, (can_u_st%10));  
            can_transmit();  
            flag=0;
        }  
        ssd[0] = digit[(can_u_st / 1000) % 10];
        ssd[1] = digit[(can_u_st / 100) % 10];
        ssd[2] = digit[(can_u_st / 10) % 10];
        ssd[3] = digit[can_u_st % 10];
        display(ssd); 
         
         
    }
}
