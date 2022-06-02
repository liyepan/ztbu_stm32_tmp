#include "stm32f10x.h"
//¿ÓÏ«≈ 210806300163
void sleep(__IO uint32_t nCount){
	for(;nCount != 0;nCount--);
}
void Close_Gpio(){
	GPIO_SetBits(GPIOB,GPIO_Pin_All);
	GPIO_SetBits(GPIOE,GPIO_Pin_All);
}

int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	Close_Gpio();
	while(1){
	  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		sleep(5000000);
		GPIO_SetBits(GPIOB,GPIO_Pin_All);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		sleep(5000000);
		GPIO_SetBits(GPIOE,GPIO_Pin_All);
	}
}
