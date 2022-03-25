#include <reg52.h>
#include "led.h"

void main(void){
	while(1){
		P1=0xff;
		sleep(20);
		P1=0x00;
	}
}