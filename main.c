#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "misc.h"
#include "stm32f10x_exti.h"
#include "init.h"




 
void SysTick_Handler(void)
{ 
     
} 
  

int main()
{
     
     SysTick_Config(SystemCoreClock/1000);//1ms  
      
     while(1)
     {
     }
     
     return 0;
}

  

