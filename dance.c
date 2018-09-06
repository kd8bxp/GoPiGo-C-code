/*
*
* GoPiGo Robot Dance
* LeRoy Miller, copyright (C) 2018
*
* Must install the gopigo library
*
* Compile: gcc dance.c -o dance -lgopigo -Wall
*
* Run: ./dance
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "gopigo.h"

void myFunction() {
printf("\nTermination Caught....\n");
stop();
exit(0);
}

int main(void) {

signal(SIGINT, myFunction);

init(); //needed for the gopigo board to work
set_left_speed(150);
set_right_speed(150);

while(1) {
fwd();
sleep(1);
stop();
bwd();
sleep(1);
stop();
left_rot();
sleep(1);
stop();
bwd();
sleep(1);
stop();
right_rot();
sleep(1);
stop();

}
}
