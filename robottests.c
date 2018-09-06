#include "gopigo.h"
 int main(void) { 
// Buffer for data being read/ written on the i2c bus 
if(init()==-1) 
exit(1); 
led_on(1);
 while(1) { 
char input[2]; /* Store 2 input characters */ 
printf("Enter cmd: "); 
scanf(" %s", &input); 
switch (input[0]) { 
case 'w': case 'W': 
fwd(); 
break; 
case 'a': case 'A': 
left(); 
break; 
case 'd': case 'D': 
right(); 
break; 
case 's': case 'S': 
bwd(); 
break; 
case 'e': case 'E': 
increase_speed(); 
break; 
case 'g': case 'G': 
decrease_speed(); 
break; 
case 'z': case 'Z': 
exit(0); 
break; 
case 'x': case 'X': 
stop(); 
break; 
case 'i': case 'I': 
motor_fwd(); 
break; 
case 'k': case 'K': 
motor_bwd(); 
break; 
case 'n': case 'N': 
left_rot(); 
break; 
case 'm': case 'M': 
right_rot(); 
break; 
case 'l': case 'L': 
switch(input[1]) { 
case 'o': case 'O': ; 
int led_val; 
printf("Enter 1 for left led and 0 for right led:\n"); 
scanf(" %d", &led_val); led_on(led_val); 
break; 
case 'f': case 'F': ; 
int led_val2; 
printf("Enter 1 for left led and 0 for right led:\n"); 
scanf(" %d", &led_val2); 
led_off(led_val2); 
break; 
default: 
printf("invalid led command... (o for ON, f for OFF)\n"); 
break; } 
break; 
case 'r': case 'R': ; 
int servo_val; 
printf("Enter servo position:\n"); 
scanf(" %d", &servo_val); 
servo(servo_val); 
break; 
case 'v': case 'V': 
printf("Firmware Version: %d\n",fw_ver()); 
break; 
case 'u': case 'U': 
printf("Ultrasonic Dist: %d\n",us_dist(15)); 
break; 
case 't': case 'T': 
switch(input[1]) { 
case 'r': case 'R': ; 
int val = trim_read();
 if(val == -3){ 
printf("-3, Trim Value Not set\n");
 } else{ 
printf("%d\n", val-100); } 
break; 
case 'w': case 'W': ; 
int val2; 
printf("Enter trim value to write to EEPROM(-100 to 100):\n"); 
scanf(" %d", &val2); 
trim_write(val2); 
pi_sleep(100); 
printf("Value in EEPROM: %d\n", trim_read()-100); 
break; 
case 't': case 'T': ; 
int val3; 
printf("Enter trim value to test(-100 to 100):\n"); 
scanf(" %d", &val3); 
trim_test(val3); 
pi_sleep(100); 
printf("Value in EEPROM: %d\n", trim_read()-100); 
break; 
default: 
printf("invalid trim command...\n"); 
break; } 
break; 
case 'c': case 'C': 
printf("Motor 0 (left) travelled %i cm\n", enc_read(0)); 
printf("Motor 1 (right) travelled %i cm\n", enc_read(1)); 
break; 
default: 
printf("invalid command...\n"); 
break; }
 }
 return 0;
 }

