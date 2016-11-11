#ifndef __INIT
#define __INIT


#define LINE_PORT GPIOA
#define LINE_PIN  GPIO_Pin_1
#define LINE_PORT_RCC RCC_APB2Periph_GPIOA

#define FRAME_PORT GPIOA
#define FRAME_PIN  GPIO_Pin_1
#define FRAME_PORT_RCC RCC_APB2Periph_GPIOA


void Gpio_Init()
{
     GPIO_InitTypeDef GPIO_InitStruct;
     
     RCC_APB2PeriphClockCmd(LINE_PORT_RCC, ENABLE);
     GPIO_InitStruct.GPIO_Pin = LINE_PIN;
     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(LINE_PORT, &GPIO_InitStruct); 
     
     RCC_APB2PeriphClockCmd(FRAME_PORT_RCC, ENABLE);
     GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_8|GPIO_Pin_7|GPIO_Pin_6;
     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(FRAME_PORT, &GPIO_InitStruct); 
     
     
}       


void Gpio_Exti_Init()
{   
     GPIO_InitTypeDef GPIO_InitStruct;
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
     GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(GPIOA, &GPIO_InitStruct);       
     
     EXTI_InitTypeDef EXTI_InitStruct;
     
     EXTI_InitStruct.EXTI_Line= EXTI_Line8;        
     EXTI_InitStruct.EXTI_Mode= EXTI_Mode_Interrupt;       
     EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising_Falling;       
     EXTI_InitStruct.EXTI_LineCmd= ENABLE;
     EXTI_Init(&EXTI_InitStruct);                                           
     
     GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
}

void Rcc_Config(void)
{      
     RCC_HCLKConfig(RCC_SYSCLK_Div1);
     RCC_PCLK1Config(RCC_HCLK_Div1);
     RCC_PCLK2Config(RCC_HCLK_Div1);
     RCC_ADCCLKConfig(RCC_PCLK2_Div2); 
}



#endif