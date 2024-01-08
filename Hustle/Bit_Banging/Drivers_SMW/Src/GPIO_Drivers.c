
/*
 * GPIO_DRIVER.c
 *
 *  Created on: Dec 12, 2023
 *      Author: 10820302
 */
#include "GPIO_Drivers.h"


/*
 * 			Initializing API
 */
void GPIO_EN_DI (GPIO_Regdef_t * pGPIO, uint8_t ENorDI)
{
	if (ENorDI == ENABLE)
	{
		//enable this in RCC
		if (pGPIO == GPIOA)
		{
			RCC->IOPENR |= (0x01 << 0);
		}
		else if (pGPIO == GPIOB)
		{
			RCC->IOPENR |= (0x01 << 1);
		}
		else if (pGPIO == GPIOC)
		{
			RCC->IOPENR |= (0x01 << 2);
		}
		else if (pGPIO == GPIOD)
		{
			RCC->IOPENR |= (0x01 << 3);
		}
		else if (pGPIO == GPIOE)
		{
			RCC->IOPENR |= (0x01 << 4);
		}
		else if (pGPIO == GPIOF)
		{
			RCC->IOPENR |= (0x01 << 5);
		}

	}

	else
		{
		if (pGPIO == GPIOA)
		{
			RCC->IOPENR &= ~(0x01 << 0);
		}
		else if (pGPIO == GPIOB)
		{
			RCC->IOPENR &= ~(0x01 << 1);
		}
		else if (pGPIO == GPIOC)
		{
			RCC->IOPENR &= ~(0x01 << 2);
		}
		else if (pGPIO == GPIOD)
		{
			RCC->IOPENR &= ~(0x01 << 3);
		}
		else if (pGPIO == GPIOE)
		{
			RCC->IOPENR &= ~(0x01 << 4);
		}
		else if (pGPIO == GPIOF)
		{
			RCC->IOPENR &= ~(0x01 << 5);
		}

		}
	}



void GPIO_INI (GPIO_Handler_t * pHandler)
{	//select the port
	pHandler->pGPIO=pHandler->config.pPort;

	//Enable the input

	//SET PUPD
	pHandler->pGPIO->PUPD &= ~(0x3 << 2*(pHandler->config.Pin));
	pHandler->pGPIO->PUPD |= pHandler->config.PUPD << 2*(pHandler->config.Pin);
	//SET ACCORDING TO MODE
	pHandler->pGPIO->Mode &= ~(0x3 << 2*(pHandler->config.Pin));
	pHandler->pGPIO->Mode |= pHandler->config.Mode << 2*(pHandler->config.Pin);
	if(pHandler->config.Mode == GPIO_MODE_IN)
	{
		// Do Nothing
	}
	else if(pHandler->config.Mode == GPIO_MODE_OUT)
	{
		pHandler->pGPIO->OutType &= ~(0x1 << (pHandler->config.Pin));
		pHandler->pGPIO->OutType |= pHandler->config.OType << pHandler->config.Pin;
		pHandler->pGPIO->OutSpeed &= ~(0x3 << (pHandler->config.Pin));
		pHandler->pGPIO->OutSpeed |= pHandler->config.OSpeed << 2*(pHandler->config.Pin);
	}
	else if(pHandler->config.Mode == GPIO_MODE_AN)
	{
		//Analog Function
	}
	else if(pHandler->config.Mode == GPIO_MODE_AF)
	{
		//Alternate function
	}


}
/*
 * 			Send data receive data
 */
void GPIO_PIN_SEND(GPIO_Regdef_t * pGPIO, uint8_t PIN, uint8_t SETorRESET)
{
	if( SETorRESET == ENABLE)
	 pGPIO->Data_OUT |= 1 << PIN ;
	else
		pGPIO->Data_OUT &= ~(1 << PIN);
}

uint8_t GPIO_PIN_READ(GPIO_Regdef_t * pGPIO, uint8_t PIN)
{
	if ((1<<PIN)& pGPIO->Data_IN)
		return 0x01;
	else
		return 0x00;
}
void GPIO_PORT_SEND(GPIO_Regdef_t * pGPIO, uint16_t Data)
{
	pGPIO->Data_IN= Data;
}
uint16_t GPIO_PORT_READ(GPIO_Regdef_t * pGPIO)
{
	return pGPIO->Data_IN;
}
void GPIO_PIN_Toggle(GPIO_Regdef_t * pGPIO, uint8_t PIN)
{
	pGPIO->Data_OUT ^= (0x01 << PIN);
}

