#include <stm32f10x.h>
#include <stdio.h>
u16 RxData; 
NVIC_InitTypeDef NVIC_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;
USART_InitTypeDef USART_InitStructure; 

void RCC_Config()
{
	//????
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
}

void NVIC_Config()
{
  
  /* Configure the Priority Grouping with 1 bit */ 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
  /* Enable EXTI0 global interrupt with Preemption Priority 0 and Sub 
  Priority as 2 */ 
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
  NVIC_Init(&NVIC_InitStructure);
}

void EXTI4_Config()
{
  /* Enables external lines 0 interrupt generation on falling 
  edge */
  EXTI_InitStructure.EXTI_Line = EXTI_Line4; 
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE; 
  EXTI_Init(&EXTI_InitStructure);
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void USART1_Config()
{
  //PA9  Tx
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	//PA10 Rx
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	//????
  
  USART_InitStructure.USART_BaudRate = 9600; 
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; 
  USART_InitStructure.USART_StopBits = USART_StopBits_1; 
  USART_InitStructure.USART_Parity = USART_Parity_No; 
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; 
  USART_Init(USART1, &USART_InitStructure);	
	//????1
	USART_Cmd(USART1, ENABLE);
}

void LED_Config()
{
	//??GPIOB PB0 PB1 PB5???????
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}


int main()
{
	RCC_Config();
	LED_Config();
	USART1_Config();
	NVIC_Config();
	EXTI4_Config();
  GPIO_SetBits(GPIOB, GPIO_Pin_All);
	printf("\n\r-USART Printf Example-\n\r");

 while(1)
	{
		
	}	
	
}



/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int fputc(int ch, FILE *f)
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}
