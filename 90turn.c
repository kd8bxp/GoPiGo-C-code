/*
*
* GoPiGo Robot 90 degree turn
* LeRoy Miller, copyright (C) 2018
*
* Must install the gopigo library
*
* Compile: gcc dance.c -o dance -lgopigo -Wall
*
* Run: ./90turn
*
*/

#include "gopigo.h"

int main(void) {

init(); //needed for the gopigo board to work
set_left_speed(150);
set_right_speed(150);
enable_encoders();

enc_tgt(0,1,12);
left_rot();

}
