/*
*
* GoPiGo Robot Blink LEDs
* Sep 2, 2018
* LeRoy Miller, copyright (C) 2018
*
* Must install the gopigo library
*
* Compile: gcc dance.c -o dance -lgopigo -Wall
*
* Run: ./dance
*
*/

#include "gopigo.h"

int main(void) {
init(); //needed for the gopigo board to work

while(1) {
led_on(1);
led_off(0);
sleep(1);
led_off(1);
led_on(0);
sleep(1);
}
}
