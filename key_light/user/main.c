#include "stm32f10x.h"
//¿ÓÏ«≈ -210806300163
void close_light_pin(void);
unsigned int  ReadValue;

int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	close_light_pin();
	while(1){
		ReadValue = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
		if(ReadValue == 1){
			close_light_pin();
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);//green
		}else if(ReadValue == 0){
			close_light_pin();
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);//blue
		}
	}
}
void close_light_pin(void){
	GPIO_SetBits(GPIOB,GPIO_Pin_All);
}
