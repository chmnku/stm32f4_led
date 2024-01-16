/*
 * ap.c
 *
 *  Created on: Jan 6, 2024
 *      Author: chmnq
 */


#include "ap.h"





void apInit(void)
{

}

void apMain(void)
{
  while(1)
  {
    //HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
    ledToggle(_DEF_LED1);
    ledToggle(_DEF_LED2);
    ledToggle(_DEF_LED3);
    delay(500);
  }
}
