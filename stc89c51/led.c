#include <reg52.h>

void sleep(unsigned int n){
	unsigned char i;
	while(n--){
		for(i=0;i<113;i++);
	}
}