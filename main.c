#include "stm32f4xx.h"                  // Device header

// stm32_led_blink_PushButton_baremetal
// B1 / PA0

int main(void){ 
		RCC->AHB1ENR |= 0x8000; // enable port D  (for LED PD6)
		RCC->AHB1ENR |= 0x1;    // enable port A  (for push button PA0)
		GPIOD->MODER |= 0x40000000; // make pin D as output (2bits/pin of 32bits)
	
		while(1){
			if(GPIOA->IDR & 0x1){  // if PA0 is hight (push button not pressed)
				GPIOD->BSRR = 0x80000000u; // turn off Led PD6
			} 
			else{
			  GPIOD->BSRR = 0x8000u;  // turn on Led PD6
			} 
		}
}
	