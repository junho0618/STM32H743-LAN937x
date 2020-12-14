/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PC14-OSC32_IN (OSC32_IN)   ------> RCC_OSC32_IN
     PC15-OSC32_OUT (OSC32_OUT)   ------> RCC_OSC32_OUT
     PH0-OSC_IN (PH0)   ------> RCC_OSC_IN
     PH1-OSC_OUT (PH1)   ------> RCC_OSC_OUT
     PA0   ------> PWR_WKUP0
     PA13 (JTMS/SWDIO)   ------> DEBUG_JTMS-SWDIO
     PA14 (JTCK/SWCLK)   ------> DEBUG_JTCK-SWCLK
     PB3 (JTDO/TRACESWO)   ------> DEBUG_JTDO-SWO
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LOW_CAN_NSTB_Pin|LAT_L_CAN_RX_EN_Pin|LAT_H_CAN_RX_EN2_Pin|LAT_H_CAN_RX_EN1_Pin
                          |LAT_WIFI_EN_Pin|LAT_IG_DET_EN_Pin|LAT_CLK_Pin|LIN_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(WIFI_BT_PWR_EN_GPIO_Port, WIFI_BT_PWR_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, WIFI_REST_Pin|TRIG_LED_EN_RX_Pin|LIN_SW_EN_Pin|LP_WAKEUP_IN_Pin
                          |RMII_RX_ER_Pin|ETH_WAKE_IN_Pin|RGMII_RSTN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, WIFI_R_LED_EN_Pin|RMII_RSTN_Pin|POWER_LED_EN_Pin|DATA_GLED_EN_Pin
                          |VHC_BLUE_LED_EN_Pin|PWR_RED_LED_EN_Pin|TRIG_LED_EN_Pin|TRG_WAK_UP_EN_Pin
                          |HI_CAN_EN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, V24_PWR_DET_EN_Pin|DATA_RLED_EN_Pin|V12_PWR_DET_EN_Pin|ETH_PWR_EN_Pin
                          |ETH_ACT_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, HSM_RST_Pin|HSM_PWR_EN_Pin|LOW_CAN_EN_Pin|EN_AB_Pin
                          |EN_CD_Pin|HI_CAN_EN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SD_PWR_EN_GPIO_Port, SD_PWR_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                           PEPin PEPin PEPin PEPin */
  GPIO_InitStruct.Pin = LOW_CAN_NSTB_Pin|LAT_L_CAN_RX_EN_Pin|LAT_H_CAN_RX_EN2_Pin|LAT_H_CAN_RX_EN1_Pin
                          |LAT_WIFI_EN_Pin|LAT_IG_DET_EN_Pin|LAT_CLK_Pin|LIN_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = WIFI_BT_PWR_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(WIFI_BT_PWR_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PF2 PF3 PF9 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PFPin PFPin PFPin PFPin
                           PFPin PFPin PFPin */
  GPIO_InitStruct.Pin = WIFI_REST_Pin|TRIG_LED_EN_RX_Pin|LIN_SW_EN_Pin|LP_WAKEUP_IN_Pin
                          |RMII_RX_ER_Pin|ETH_WAKE_IN_Pin|RGMII_RSTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PFPin PFPin */
  GPIO_InitStruct.Pin = SPI1_INTR_Pin|TRIG_KEY_INT_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = ULP_WAKUP_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ULP_WAKUP_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC2 PC3 PC6 PC7
                           PC8 PC9 PC10 PC11
                           PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin PBPin
                           PBPin */
  GPIO_InitStruct.Pin = WIFI_R_LED_EN_Pin|RMII_RSTN_Pin|POWER_LED_EN_Pin|DATA_GLED_EN_Pin
                          |VHC_BLUE_LED_EN_Pin|PWR_RED_LED_EN_Pin|TRIG_LED_EN_Pin|TRG_WAK_UP_EN_Pin
                          |HI_CAN_EN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = WIFI_ON_OFF_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(WIFI_ON_OFF_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PAIR_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PAIR_SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PG0 PG2 PG8 PG15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_8|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = T1_PHY_LED_Pin|BD_ID1_Pin|BD_ID0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin */
  GPIO_InitStruct.Pin = TX_PHY_LED_Pin|GIGA_PHY_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin */
  GPIO_InitStruct.Pin = V24_PWR_DET_EN_Pin|DATA_RLED_EN_Pin|V12_PWR_DET_EN_Pin|ETH_PWR_EN_Pin
                          |ETH_ACT_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD11 PD12 PD2 PD3
                           PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin PGPin
                           PGPin PGPin */
  GPIO_InitStruct.Pin = HSM_RST_Pin|HSM_PWR_EN_Pin|LOW_CAN_EN_Pin|EN_AB_Pin
                          |EN_CD_Pin|HI_CAN_EN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = VBUS_Pin|USB_ID_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SD_PWR_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SD_PWR_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin */
  GPIO_InitStruct.Pin = SDIO_WP_Pin|SDIO_CD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
