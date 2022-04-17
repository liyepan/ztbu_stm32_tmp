#include "stm32f10x.h"
//¿ÓÏ«≈ -210806300163
void sleep(__IO uint32_t nCount);
void close_light_pin(void);

int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	while(1){
		close_light_pin();
	  GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_5);//yellow
		sleep(100000);
		close_light_pin();
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);//green
		sleep(100000);
		close_light_pin();
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);//blue
		sleep(100000);
	}
}

void sleep(__IO uint32_t nCount){
	for(;nCount != 0;nCount--);
}

void close_light_pin(){
	GPIO_SetBits(GPIOB,GPIO_Pin_All);
}
