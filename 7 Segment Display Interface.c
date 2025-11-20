/*
 * 7 Segment Display Interface.c
 *
 * Created: 12-08-2025 09:15:57
 * Author : asath
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	int segment[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F},i;
    /* Replace with your application code */
    while (1) 
    {
		for (i=0;i<10;i++)
		{
			PORTD = segment[i];
			_delay_ms(1000);
		}
    }
}

