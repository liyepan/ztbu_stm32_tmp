#include "stm32f10x.h"
//¿ÓÏ«≈ -210806300163
void close_light_pin(void);
unsigned int  ReadValue;

int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	//led
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	//key
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	close_light_pin();
	while(1){
		close_light_pin();
		ReadValue = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3);
		if(ReadValue == 0){
			GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		}
		if(ReadValue == 1){
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		}
	}
}
void close_light_pin(void){
	GPIO_SetBits(GPIOB,GPIO_Pin_All);
	GPIO_SetBits(GPIOE,GPIO_Pin_All);
}
