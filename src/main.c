#include <main.h>

void delay_ms(uint64_t delay){
	for(uint64_t i = 0; i < delay*169; i++){
	}
}

int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 1 << 10;
	GPIOA->OSPEEDR |= 1 << 10;
	while(1) 
	{
		delay_ms(1000);
		GPIOA->ODR |= 1 << 5;
		delay_ms(1000);
		GPIOA->ODR &= ~(1 << 5);
	}
}






