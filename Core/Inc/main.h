/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LOW_CAN_NSTB_Pin GPIO_PIN_3
#define LOW_CAN_NSTB_GPIO_Port GPIOE
#define WIFI_BT_PWR_EN_Pin GPIO_PIN_13
#define WIFI_BT_PWR_EN_GPIO_Port GPIOC
#define I2C_SDA_Pin GPIO_PIN_0
#define I2C_SDA_GPIO_Port GPIOF
#define I2C_SCL_Pin GPIO_PIN_1
#define I2C_SCL_GPIO_Port GPIOF
#define WIFI_REST_Pin GPIO_PIN_4
#define WIFI_REST_GPIO_Port GPIOF
#define SPI1_INTR_Pin GPIO_PIN_5
#define SPI1_INTR_GPIO_Port GPIOF
#define TRIG_LED_EN_RX_Pin GPIO_PIN_6
#define TRIG_LED_EN_RX_GPIO_Port GPIOF
#define TRIG_KEY_INT_TX_Pin GPIO_PIN_7
#define TRIG_KEY_INT_TX_GPIO_Port GPIOF
#define LIN_SW_EN_Pin GPIO_PIN_8
#define LIN_SW_EN_GPIO_Port GPIOF
#define LP_WAKEUP_IN_Pin GPIO_PIN_10
#define LP_WAKEUP_IN_GPIO_Port GPIOF
#define ULP_WAKUP_IN_Pin GPIO_PIN_0
#define ULP_WAKUP_IN_GPIO_Port GPIOC
#define ETH_MDC_Pin GPIO_PIN_1
#define ETH_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define ETH_MDIO_Pin GPIO_PIN_2
#define ETH_MDIO_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_3
#define DEBUG_RX_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define WIFI_R_LED_EN_Pin GPIO_PIN_0
#define WIFI_R_LED_EN_GPIO_Port GPIOB
#define WIFI_ON_OFF_INT_Pin GPIO_PIN_1
#define WIFI_ON_OFF_INT_GPIO_Port GPIOB
#define RMII_RSTN_Pin GPIO_PIN_2
#define RMII_RSTN_GPIO_Port GPIOB
#define BAT_ADC_Pin GPIO_PIN_11
#define BAT_ADC_GPIO_Port GPIOF
#define PAIR_SW_Pin GPIO_PIN_12
#define PAIR_SW_GPIO_Port GPIOF
#define RMII_RX_ER_Pin GPIO_PIN_13
#define RMII_RX_ER_GPIO_Port GPIOF
#define ETH_WAKE_IN_Pin GPIO_PIN_14
#define ETH_WAKE_IN_GPIO_Port GPIOF
#define RGMII_RSTN_Pin GPIO_PIN_15
#define RGMII_RSTN_GPIO_Port GPIOF
#define T1_PHY_LED_Pin GPIO_PIN_1
#define T1_PHY_LED_GPIO_Port GPIOG
#define TX_PHY_LED_Pin GPIO_PIN_7
#define TX_PHY_LED_GPIO_Port GPIOE
#define GIGA_PHY_LED_Pin GPIO_PIN_8
#define GIGA_PHY_LED_GPIO_Port GPIOE
#define LAT_L_CAN_RX_EN_Pin GPIO_PIN_9
#define LAT_L_CAN_RX_EN_GPIO_Port GPIOE
#define LAT_H_CAN_RX_EN2_Pin GPIO_PIN_10
#define LAT_H_CAN_RX_EN2_GPIO_Port GPIOE
#define LAT_H_CAN_RX_EN1_Pin GPIO_PIN_11
#define LAT_H_CAN_RX_EN1_GPIO_Port GPIOE
#define LAT_WIFI_EN_Pin GPIO_PIN_12
#define LAT_WIFI_EN_GPIO_Port GPIOE
#define LAT_IG_DET_EN_Pin GPIO_PIN_13
#define LAT_IG_DET_EN_GPIO_Port GPIOE
#define LAT_CLK_Pin GPIO_PIN_14
#define LAT_CLK_GPIO_Port GPIOE
#define LIN_EN_Pin GPIO_PIN_15
#define LIN_EN_GPIO_Port GPIOE
#define POWER_LED_EN_Pin GPIO_PIN_12
#define POWER_LED_EN_GPIO_Port GPIOB
#define DATA_GLED_EN_Pin GPIO_PIN_13
#define DATA_GLED_EN_GPIO_Port GPIOB
#define VHC_BLUE_LED_EN_Pin GPIO_PIN_14
#define VHC_BLUE_LED_EN_GPIO_Port GPIOB
#define PWR_RED_LED_EN_Pin GPIO_PIN_15
#define PWR_RED_LED_EN_GPIO_Port GPIOB
#define V24_PWR_DET_EN_Pin GPIO_PIN_8
#define V24_PWR_DET_EN_GPIO_Port GPIOD
#define DATA_RLED_EN_Pin GPIO_PIN_9
#define DATA_RLED_EN_GPIO_Port GPIOD
#define V12_PWR_DET_EN_Pin GPIO_PIN_10
#define V12_PWR_DET_EN_GPIO_Port GPIOD
#define BUZZER_PWM_Pin GPIO_PIN_13
#define BUZZER_PWM_GPIO_Port GPIOD
#define ETH_PWR_EN_Pin GPIO_PIN_14
#define ETH_PWR_EN_GPIO_Port GPIOD
#define ETH_ACT_EN_Pin GPIO_PIN_15
#define ETH_ACT_EN_GPIO_Port GPIOD
#define HSM_RST_Pin GPIO_PIN_3
#define HSM_RST_GPIO_Port GPIOG
#define HSM_PWR_EN_Pin GPIO_PIN_4
#define HSM_PWR_EN_GPIO_Port GPIOG
#define LOW_CAN_EN_Pin GPIO_PIN_5
#define LOW_CAN_EN_GPIO_Port GPIOG
#define BD_ID1_Pin GPIO_PIN_6
#define BD_ID1_GPIO_Port GPIOG
#define BD_ID0_Pin GPIO_PIN_7
#define BD_ID0_GPIO_Port GPIOG
#define VBUS_Pin GPIO_PIN_9
#define VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_FS_DM1_Pin GPIO_PIN_11
#define USB_FS_DM1_GPIO_Port GPIOA
#define USB_FS_DP1_Pin GPIO_PIN_12
#define USB_FS_DP1_GPIO_Port GPIOA
#define SD_PWR_EN_Pin GPIO_PIN_15
#define SD_PWR_EN_GPIO_Port GPIOA
#define CAN_RX1_Pin GPIO_PIN_0
#define CAN_RX1_GPIO_Port GPIOD
#define CAN_TX1_Pin GPIO_PIN_1
#define CAN_TX1_GPIO_Port GPIOD
#define SDIO_WP_Pin GPIO_PIN_4
#define SDIO_WP_GPIO_Port GPIOD
#define DEBUG_TX_Pin GPIO_PIN_5
#define DEBUG_TX_GPIO_Port GPIOD
#define SDIO_CD_Pin GPIO_PIN_6
#define SDIO_CD_GPIO_Port GPIOD
#define EN_AB_Pin GPIO_PIN_9
#define EN_AB_GPIO_Port GPIOG
#define EN_CD_Pin GPIO_PIN_10
#define EN_CD_GPIO_Port GPIOG
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD1_Pin GPIO_PIN_12
#define RMII_TXD1_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define HI_CAN_EN1_Pin GPIO_PIN_14
#define HI_CAN_EN1_GPIO_Port GPIOG
#define CAN_RX2_Pin GPIO_PIN_5
#define CAN_RX2_GPIO_Port GPIOB
#define CAN_TX2_Pin GPIO_PIN_6
#define CAN_TX2_GPIO_Port GPIOB
#define TRIG_LED_EN_Pin GPIO_PIN_7
#define TRIG_LED_EN_GPIO_Port GPIOB
#define TRG_WAK_UP_EN_Pin GPIO_PIN_8
#define TRG_WAK_UP_EN_GPIO_Port GPIOB
#define HI_CAN_EN2_Pin GPIO_PIN_9
#define HI_CAN_EN2_GPIO_Port GPIOB
#define HSM_RX_Pin GPIO_PIN_0
#define HSM_RX_GPIO_Port GPIOE
#define HSM_TX_Pin GPIO_PIN_1
#define HSM_TX_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
