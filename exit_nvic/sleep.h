#include  "stm32f10x.h"
void sleep(__IO uint32_t nCount){
	for(;nCount != 0;nCount--);
}