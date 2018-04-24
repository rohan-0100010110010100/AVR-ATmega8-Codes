/*
 * Light_Searching_ATmega8.c
 *
 * Created: 24-Apr-18 10:59:41 AM
 * Author : rohan
 */ 

/* Program for "LIGHT_SEARCHING_BOT/Search for Light using Light Sensors connected on PB0
___________________________________________________________________________________________

Connection Settings of the Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
LIGHT SENSOR--------->PBO
Right Sensor--------->PC0
Buzzer--------------->PD4
SOUND SENSOR--------->PB0
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLoader Condition Check----->PC5(If 0 bootloader section else program execution
							    section of Flash memory)
RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/
#define F_CPU 12000000UL
#include<avr/io.h>
int main(void)
{
DDRB=0b11111110; // PORTB as output Port connected to motors and PB0 as input port connected to sensor

int light_sensor=0;

while(1) // infinite loop
{
      light_sensor=PINB&0b00000001; // mask PB0 bit of Port B
      
	  if(light_sensor==0b00000001) //if Light source is on robot's left side "
      PORTB=0b00000001; // move left
      
	  else
      
	  PORTB=0b00001000; // move right
 
 }//while closed

}//main closed
