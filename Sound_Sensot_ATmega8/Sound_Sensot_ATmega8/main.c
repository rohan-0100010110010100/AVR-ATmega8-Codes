/*
 * Sound_Sensot_ATmega8.c
 *
 * Created: 24-Apr-18 10:24:31 AM
 * Author : rohan
 */ 

/* Program for "START_ON_CLAP/Changing the Stop state of BOT on Clap Using Sound Sensor"
_________________________________________________________________________________________________

Connection Settings of the Kit
sound sensor--------->PC0
LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
left sensor---------->PC0
right sensor--------->PC3
SOUND SENSOR--------->PB0
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4

BOOTLoAder Condition Check----->PC5(If 0 bootloader section else program execution
section of Flash memory)
RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 and PB7(Hence PB6 and PB7 are not available for user)
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#include<avr/io.h>
#include<util/delay.h>

void wait(float sec)
{
	for(int i=0;i<(int)46*sec;i++)
	_delay_loop_2(0);
}


int main(void)
{

DDRB=0b00011110;  //PB1, PB2, PB3, PB4 as output port
int ss=0;         // define & initialize ss integer as  0 to acquire the sound sensor status in ss

while(1)          // create infinite loop
{
ss=(PINB&0b0000001);      //acquire only sound sensor status connected at PB0

if(ss==0b0000001)	  //check for sound sensor ON status at PB0
{

PORTB=0b00010010;    //forward
wait(5);
PORTB=0b00000000;	  //stop

}

}

}
