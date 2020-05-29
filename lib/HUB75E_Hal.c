/*
 * HUB75E_Hal.c
 *
 *  Created on: May 28, 2020
 *      Author: raeeskattali
 */
#include "HUB75E_Hal.h"
#include "stm32f2xx_hal.h"
#include "dwt_delay.h"

//IO Pins & Ports
#define LED_MATRIX_B2_Pin GPIO_PIN_15
#define LED_MATRIX_B2_GPIO_Port GPIOA
#define LED_MATRIX_G2_Pin GPIO_PIN_3
#define LED_MATRIX_G2_GPIO_Port GPIOB
#define LED_MATRIX_B1_Pin GPIO_PIN_5
#define LED_MATRIX_B1_GPIO_Port GPIOB
#define LED_MATRIX_R1_Pin GPIO_PIN_7
#define LED_MATRIX_R1_GPIO_Port GPIOB
#define LED_MATRIX_R2_Pin GPIO_PIN_4
#define LED_MATRIX_R2_GPIO_Port GPIOB
#define LED_MATRIX_G1_Pin GPIO_PIN_6
#define LED_MATRIX_G1_GPIO_Port GPIOB
#define LED_MATRIX_LATCH_Pin GPIO_PIN_10
#define LED_MATRIX_LATCH_GPIO_Port GPIOA
#define LED_MATRIX_ADDRESS_LINE_C_Pin GPIO_PIN_2
#define LED_MATRIX_ADDRESS_LINE_C_GPIO_Port GPIOC
#define LED_MATRIX_CLK_Pin GPIO_PIN_9
#define LED_MATRIX_CLK_GPIO_Port GPIOA
#define LED_MATRIX_ADDRESS_LINE_A_Pin GPIO_PIN_5
#define LED_MATRIX_ADDRESS_LINE_A_GPIO_Port GPIOC
#define LED_MATRIX_ADDRESS_LINE_B_Pin GPIO_PIN_3
#define LED_MATRIX_ADDRESS_LINE_B_GPIO_Port GPIOC
#define LED_MATRIX_ADDRESS_LINE_E_Pin GPIO_PIN_6
#define LED_MATRIX_ADDRESS_LINE_E_GPIO_Port GPIOA
#define LED_MATRIX_ADDRESS_LINE_D_Pin GPIO_PIN_5
#define LED_MATRIX_ADDRESS_LINE_D_GPIO_Port GPIOA
#define LED_MATRIX_OE_Pin GPIO_PIN_7
#define LED_MATRIX_OE_GPIO_Port GPIOA
//

void HUB75E_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_MATRIX_B2_Pin|LED_MATRIX_LATCH_Pin|LED_MATRIX_CLK_Pin
                          |LED_MATRIX_ADDRESS_LINE_E_Pin|LED_MATRIX_ADDRESS_LINE_D_Pin|LED_MATRIX_OE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_MATRIX_G2_Pin|LED_MATRIX_B1_Pin|LED_MATRIX_R1_Pin|LED_MATRIX_R2_Pin
                          |LED_MATRIX_G1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_MATRIX_ADDRESS_LINE_C_Pin|LED_MATRIX_ADDRESS_LINE_A_Pin|LED_MATRIX_ADDRESS_LINE_B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_MATRIX_B2_Pin LED_MATRIX_LATCH_Pin LED_MATRIX_CLK_Pin LED_Blue_Pin
                           LED_MATRIX_ADDRESS_LINE_E_Pin LED_MATRIX_ADDRESS_LINE_D_Pin LED_Red_Pin LED_MATRIX_OE_Pin
                           LED_Green_Pin */
  GPIO_InitStruct.Pin = LED_MATRIX_B2_Pin|LED_MATRIX_LATCH_Pin|LED_MATRIX_CLK_Pin
                          |LED_MATRIX_ADDRESS_LINE_E_Pin|LED_MATRIX_ADDRESS_LINE_D_Pin|LED_MATRIX_OE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_MATRIX_G2_Pin LED_MATRIX_B1_Pin LED_MATRIX_R1_Pin LED_MATRIX_R2_Pin
                           LED_MATRIX_G1_Pin */
  GPIO_InitStruct.Pin = LED_MATRIX_G2_Pin|LED_MATRIX_B1_Pin|LED_MATRIX_R1_Pin|LED_MATRIX_R2_Pin
                          |LED_MATRIX_G1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_MATRIX_ADDRESS_LINE_C_Pin LED_MATRIX_ADDRESS_LINE_A_Pin LED_MATRIX_ADDRESS_LINE_B_Pin */
  GPIO_InitStruct.Pin = LED_MATRIX_ADDRESS_LINE_C_Pin|LED_MATRIX_ADDRESS_LINE_A_Pin|LED_MATRIX_ADDRESS_LINE_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

void HUB75E_DelayUs(int us) {
	DWT_Delay(us);
}

void HUB75E_setPin(HUB75EPin p, int state) {

	 switch (p)	 {
	 	 case PinRed1:
	 		HAL_GPIO_WritePin(LED_MATRIX_R1_GPIO_Port, LED_MATRIX_R1_Pin, state);
	 		 break;
	 	case PinBlue1:
	 		HAL_GPIO_WritePin(LED_MATRIX_B1_GPIO_Port, LED_MATRIX_B1_Pin, state);
	 		break;
	 	case PinGreen1:
	 		HAL_GPIO_WritePin(LED_MATRIX_G1_GPIO_Port, LED_MATRIX_G1_Pin, state);
	 		break;
	 	case PinRed2:
	 		HAL_GPIO_WritePin(LED_MATRIX_R2_GPIO_Port, LED_MATRIX_R2_Pin, state);
	 		break;
	 	case PinBlue2:
	 		HAL_GPIO_WritePin(LED_MATRIX_B2_GPIO_Port, LED_MATRIX_B2_Pin, state);
	 		break;
	 	case PinGreen2:
	 		HAL_GPIO_WritePin(LED_MATRIX_G2_GPIO_Port, LED_MATRIX_G2_Pin, state);
	 		break;
	 	case PinADDRA:
	 		HAL_GPIO_WritePin(LED_MATRIX_ADDRESS_LINE_A_GPIO_Port, LED_MATRIX_ADDRESS_LINE_A_Pin, state);
	 		break;
	 	case PinADDRB:
	 		HAL_GPIO_WritePin(LED_MATRIX_ADDRESS_LINE_B_GPIO_Port, LED_MATRIX_ADDRESS_LINE_B_Pin, state);
	 		break;
	 	case PinADDRC:
	 		HAL_GPIO_WritePin(LED_MATRIX_ADDRESS_LINE_C_GPIO_Port, LED_MATRIX_ADDRESS_LINE_C_Pin, state);
	 		break;
	 	case PinADDRD:
	 		HAL_GPIO_WritePin(LED_MATRIX_ADDRESS_LINE_D_GPIO_Port, LED_MATRIX_ADDRESS_LINE_D_Pin, state);
	 		break;
	 	case PinADDRE:
	 		HAL_GPIO_WritePin(LED_MATRIX_ADDRESS_LINE_E_GPIO_Port, LED_MATRIX_ADDRESS_LINE_E_Pin, state);
	 		break;
	 	case PinCLK:
	 		HAL_GPIO_WritePin(LED_MATRIX_CLK_GPIO_Port, LED_MATRIX_CLK_Pin, state);
	 		break;
	 	case PinLATCH:
	 		HAL_GPIO_WritePin(LED_MATRIX_LATCH_GPIO_Port, LED_MATRIX_LATCH_Pin, state);
	 		break;
	 	case PinOE:
	 		HAL_GPIO_WritePin(LED_MATRIX_OE_GPIO_Port, LED_MATRIX_OE_Pin, state);
	 		break;
	 	default:
	 		break;
	 }

}
