/*
*
* GoPiGo Robot Ultrasonic Demo
* LeRoy Miller, copyright (C) 2018
*
* Must install the gopigo library
*
* Compile: gcc ultrasonicdemo.c -o usdemo -lgopigo -Wall
*
* Run: ./usdemo
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
enable_encoders();

while(1) {

while (us_dist(15) >= 13) {
fwd();
}

stop();
enc_tgt(0,1,12);
left_rot();
set_left_speed(150);
set_right_speed(150);

  }
}
