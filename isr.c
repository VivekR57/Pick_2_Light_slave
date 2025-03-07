#include <xc.h>
extern unsigned int key_detected;
extern unsigned char flag;

void __interrupt() isr(void)
{
	if (INT0F == 1)
	{
		key_detected = 1;
        flag=!flag;
		INT0F = 0;
	}
}
