/*
 * led.c
 *
 *  Created on: Jan 15, 2024
 *      Author: chmnq
 */

#include "led.h"

typedef struct
{
  GPIO_TypeDef *port;
  uint16_t      pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
} led_tbl_t;

led_tbl_t led_tbl[LED_MAX_CH]=
    {
        //{GPIOB, GPIO_PIN_12, GPIO_PIN_RESET, GPIO_PIN_SET}
        {GPIOC, GPIO_PIN_13, GPIO_PIN_RESET, GPIO_PIN_SET},
        {GPIOB, GPIO_PIN_14, GPIO_PIN_RESET, GPIO_PIN_SET},
        {GPIOB, GPIO_PIN_15, GPIO_PIN_RESET, GPIO_PIN_SET}
    };


bool ledInit(void)
{
  bool ret = true;

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  // comment out unnecessary code (GPIOH, GPIOA)
  //__HAL_RCC_GPIOH_CLK_ENABLE();
  //__HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  //__HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  // Blink the LED each 0.5 seconds.
  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);

  /*Configure GPIO pin : PB12 */
  //GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  //HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


  for (int i=0; i<LED_MAX_CH; i++)
  {
    GPIO_InitStruct.Pin = led_tbl[i].pin;
    HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);

    ledOff(i);
  }

  return ret;
}

void ledOn(uint8_t ch)
{
  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  if (ch >= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
  if (ch >= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
  if (ch >= LED_MAX_CH) return;
  HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}
