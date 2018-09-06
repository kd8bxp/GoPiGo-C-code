/*
*
* GoPiGo Robot volt
* LeRoy Miller, copyright (C) 2018
*
* Must install the gopigo library
*
* Compile: gcc dance.c -o dance -lgopigo -Wall
*
* Run: ./volt
*
*/

#include "gopigo.h"

int main(void) {

init(); //needed for the gopigo board to work
printf("Volts: %f\n ",volt());

}
