#include "stm32f0xx.h"

int main() {
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB->MODER |= GPIO_MODER_MODER3_0;

    while (1) {
        GPIOB->BSRR |= GPIO_BSRR_BS_3;
        for (uint32_t i = 0; i < 1000000; i++);
        GPIOB->BSRR |= GPIO_BSRR_BR_3;
        for (uint32_t i = 0; i < 1000000; i++);
    }
}