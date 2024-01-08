/*
 * 02.Test_SPI.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Sarang
 */

#include <stdint.h>
#include "G0B1re_drivers.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void SPI_Setup(SPI_Handler_t * SPI)
{
	SPI->SPI_Config.Baudrate =
}

int main()
{
	SPI_Handler_t SPI;

	SPI_setup();
}
