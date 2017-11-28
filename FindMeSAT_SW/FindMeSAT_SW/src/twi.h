/*
 * \file
 *
 * \brief FindMeSAT
 * twi.h
 *
 * Created: 07.06.2017 22:48:48
 * Author : DF4IAH
 */


#ifndef TWI_H_
#define TWI_H_

#include <asf.h>


/* Smart-LCD address and command-set */

// I2C address of the Smart-LCD device
#define TWI_SMART_LCD_ADDR											0x22

// unique commands of the Smart-LCD device for all modes
#define TWI_SMART_LCD_CMD_NOOP										0x00
#define TWI_SMART_LCD_CMD_GET_VER									0x01
#define TWI_SMART_LCD_CMD_SET_MODE									0x02
#define TWI_SMART_LCD_CMD_GET_STATE									0x03

// mode 0x10 commands (Smart-LCD draw box)
#define TWI_SMART_LCD_CMD_RESET										0x10
#define TWI_SMART_LCD_CMD_CLS										0x11
#define TWI_SMART_LCD_CMD_SET_PIXEL_TYPE							0x14
#define TWI_SMART_LCD_CMD_SET_POS_X_Y								0x20
#define TWI_SMART_LCD_CMD_WRITE										0x30
#define TWI_SMART_LCD_CMD_DRAW_LINE									0x32
#define TWI_SMART_LCD_CMD_DRAW_RECT									0x34
#define TWI_SMART_LCD_CMD_DRAW_FILLED_RECT							0x36
#define TWI_SMART_LCD_CMD_DRAW_CIRC									0x38
#define TWI_SMART_LCD_CMD_DRAW_FILLED_CIRC							0x3A
#define TWI_SMART_LCD_CMD_GET_ROTBUT								0x60
#define TWI_SMART_LCD_CMD_GET_LIGHT									0x64
#define TWI_SMART_LCD_CMD_GET_TEMP									0x65
#define TWI_SMART_LCD_CMD_SET_LEDS									0x70
#define TWI_SMART_LCD_CMD_SET_BEEP									0x71
#define TWI_SMART_LCD_CMD_SET_BACKLIGHT								0x74
#define TWI_SMART_LCD_CMD_SET_CONTRAST								0x75

// mode 0x20 commands (10 MHz-Ref-Osc)
#define TWI_SMART_LCD_CMD_SHOW_CLK_STATE							0x80
#define TWI_SMART_LCD_CMD_SHOW_YEAR_MON_DAY							0x81
#define TWI_SMART_LCD_CMD_SHOW_HR_MIN_SEC							0x82
#define TWI_SMART_LCD_CMD_SHOW_PPB									0x83

#define TWI_SMART_LCD_CMD_SHOW_TCXO_PWM								0x84
#define TWI_SMART_LCD_CMD_SHOW_TCXO_VC								0x85

#define TWI_SMART_LCD_CMD_SHOW_SATS									0x88
#define TWI_SMART_LCD_CMD_SHOW_DOP									0x89
#define TWI_SMART_LCD_CMD_SHOW_POS_STATE							0x8A
#define TWI_SMART_LCD_CMD_SHOW_POS_LAT								0x8B
#define TWI_SMART_LCD_CMD_SHOW_POS_LON								0x8C
#define TWI_SMART_LCD_CMD_SHOW_POS_HEIGHT							0x8D

// Delay definitions
#define TWI_SMART_LCD_DEVICE_SIMPLE_DELAY_MIN_US					   1
#define TWI_SMART_LCD_DEVICE_BUSY_DELAY_MIN_US						 100
#define TWI_SMART_LCD_DEVICE_TCXOPWM_DELAY_MIN_US					1000


#define TWI1_MASTER													TWIE
//#define TWI1_SLAVE												TWIE
#define TWI1_MASTER_PORT											PORTE
#define TWI1_MASTER_ADDR											0x10
#define TWI1_SLAVE_ADDR												0x12
#define TWI1_SPEED													400000


//#define TWI1_SLAVE_GSM_ADDR										0x00
//#define TWI1_SLAVE_GSM_REG_1_DEVICE_ID							0x00


#define TWI1_SLAVE_GYRO_ADDR_1										0x68
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_X_GYRO					0x00
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_Y_GYRO					0x01
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_Z_GYRO					0x02
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_X_ACCEL				0x0D
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_Y_ACCEL				0x0E
#define TWI1_SLAVE_GYRO_REG_1_GYRO_SELF_TEST_Z_ACCEL				0x0F
#define TWI1_SLAVE_GYRO_REG_1_GYRO_XG_OFFSET_H						0x13
#define TWI1_SLAVE_GYRO_REG_1_GYRO_XG_OFFSET_L						0x14
#define TWI1_SLAVE_GYRO_REG_1_GYRO_YG_OFFSET_H						0x15
#define TWI1_SLAVE_GYRO_REG_1_GYRO_YG_OFFSET_L						0x16
#define TWI1_SLAVE_GYRO_REG_1_GYRO_ZG_OFFSET_H						0x17
#define TWI1_SLAVE_GYRO_REG_1_GYRO_ZG_OFFSET_L						0x18
#define TWI1_SLAVE_GYRO_REG_1_SMPLRT_DIV							0x19
#define TWI1_SLAVE_GYRO_REG_1_CONFIG								0x1A

#define TWI1_SLAVE_GYRO_REG_1_GYRO_CONFIG							0x1B
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__FS_SEL_0250				0x00
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__FS_SEL_0500				0x08
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__FS_SEL_1000				0x10
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__FS_SEL_2000				0x18
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__0250DPS					 250
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__0500DPS					 500
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__1000DPS					1000
#define TWI1_SLAVE_GYRO_DTA_1_GYRO_CONFIG__2000DPS					2000

#define TWI1_SLAVE_GYRO_REG_1_ACCEL_CONFIG							0x1C
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__FS_SEL_L_02				0x00
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__FS_SEL_L_04				0x08
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__FS_SEL_L_08				0x10
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__FS_SEL_L_16				0x18
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__02G						 2
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__04G						 4
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__08G						 8
#define TWI1_SLAVE_GYRO_DTA_1_ACCEL_CONFIG__16G						16

#define TWI1_SLAVE_GYRO_REG_1_ACCEL_CONFIG2							0x1D
#define TWI1_SLAVE_GYRO_REG_1_LP_ACCEL_ODR							0x1E
#define TWI1_SLAVE_GYRO_REG_1_WOM_THR								0x1F
#define TWI1_SLAVE_GYRO_REG_1_FIFO_EN								0x23
#define TWI1_SLAVE_GYRO_REG_1_I2C_MST_CTRL							0x24
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV0_ADDR							0x25
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV0_REG							0x26
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV0_CTRL							0x27
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV1_ADDR							0x28
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV1_REG							0x29
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV1_CTRL							0x2A
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV2_ADDR							0x2B
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV2_REG							0x2C
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV2_CTRL							0x2D
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV3_ADDR							0x2E
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV3_REG							0x2F
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV3_CTRL							0x30
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV4_ADDR							0x31
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV4_REG							0x32
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV4_DO							0x33
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV4_CTRL							0x34
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV4_DI							0x35
#define TWI1_SLAVE_GYRO_REG_1_I2C_MST_STATUS						0x36

#define TWI1_SLAVE_GYRO_REG_1_INT_PIN_CFG							0x37
#define TWI1_SLAVE_GYRO_DTA_1_INT_PIN_CFG__BYPASS_EN				0x02

#define TWI1_SLAVE_GYRO_REG_1_INT_ENABLE							0x38
#define TWI1_SLAVE_GYRO_REG_1_INT_STATUS							0x3A
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_XOUT_H							0x3B
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_XOUT_L							0x3C
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_YOUT_H							0x3D
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_YOUT_L							0x3E
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_ZOUT_H							0x3F
#define TWI1_SLAVE_GYRO_REG_1_ACCEL_ZOUT_L							0x40
#define TWI1_SLAVE_GYRO_REG_1_TEMP_OUT_H							0x41
#define TWI1_SLAVE_GYRO_REG_1_TEMP_OUT_L							0x42
#define TWI1_SLAVE_GYRO_REG_1_GYRO_XOUT_H							0x43
#define TWI1_SLAVE_GYRO_REG_1_GYRO_XOUT_L							0x44
#define TWI1_SLAVE_GYRO_REG_1_GYRO_YOUT_H							0x45
#define TWI1_SLAVE_GYRO_REG_1_GYRO_YOUT_L							0x46
#define TWI1_SLAVE_GYRO_REG_1_GYRO_ZOUT_H							0x47
#define TWI1_SLAVE_GYRO_REG_1_GYRO_ZOUT_L							0x48
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_00						0x49
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_01						0x4A
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_02						0x4B
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_03						0x4C
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_04						0x4D
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_05						0x4E
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_06						0x4F
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_07						0x50
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_08						0x51
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_09						0x52
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_10						0x53
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_11						0x54
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_12						0x55
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_13						0x56
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_14						0x57
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_15						0x58
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_16						0x59
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_17						0x5A
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_18						0x5B
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_19						0x5C
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_20						0x5D
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_21						0x5E
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_22						0x5F
#define TWI1_SLAVE_GYRO_REG_1_EXT_SENS_DATA_23						0x60
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV0_DO							0x63
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV1_DO							0x64
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV2_DO							0x65
#define TWI1_SLAVE_GYRO_REG_1_I2C_SLV3_DO							0x66
#define TWI1_SLAVE_GYRO_REG_1_I2C_MST_DELAY_CTRL					0x67

#define TWI1_SLAVE_GYRO_REG_1_SIGNAL_PATH_RESET						0x68
#define TWI1_SLAVE_GYRO_DTA_1_SIGNAL_PATH_RESET__TEMP_RST			0x01
#define TWI1_SLAVE_GYRO_DTA_1_SIGNAL_PATH_RESET__ACCEL_RST			0x02
#define TWI1_SLAVE_GYRO_DTA_1_SIGNAL_PATH_RESET__GYRO_RST			0x04

#define TWI1_SLAVE_GYRO_REG_1_MOT_DETECT_CTRL						0x69

#define TWI1_SLAVE_GYRO_REG_1_USER_CTRL								0x6A
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__SIG_COND_RST				0x01
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__I2C_MST_RST				0x02
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__FIFO_RST					0x04
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__I2C_IF_DIS					0x10
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__2C_MST_EN					0x20
#define TWI1_SLAVE_GYRO_DTA_1_USER_CTRL__FIFO_EN					0x40

#define TWI1_SLAVE_GYRO_REG_1_PWR_MGMT_1							0x6B
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__CLKSEL_VAL				0x01	// Clock: auto select
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__PD_PTAT					0x08
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__GYRO_STANDBY				0x10
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__CYCLE						0x20
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__SLEEP						0x40
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_1__HRESET					0x80

#define TWI1_SLAVE_GYRO_REG_1_PWR_MGMT_2							0x6C
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_ZG				0x01
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_YG				0x02
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_XG				0x04
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_ZA				0x08
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_YA				0x10
#define TWI1_SLAVE_GYRO_DTA_1_PWR_MGMT_2__DISABLE_XA				0x20

#define TWI1_SLAVE_GYRO_REG_1_FIFO_COUNTH							0x72
#define TWI1_SLAVE_GYRO_REG_1_FIFO_COUNTL							0x73
#define TWI1_SLAVE_GYRO_REG_1_FIFO_R_W								0x74
#define TWI1_SLAVE_GYRO_REG_1_WHOAMI								0x75
#define TWI1_SLAVE_GYRO_REG_1_XA_OFFSET_H							0x77
#define TWI1_SLAVE_GYRO_REG_1_XA_OFFSET_L							0x78
#define TWI1_SLAVE_GYRO_REG_1_YA_OFFSET_H							0x7A
#define TWI1_SLAVE_GYRO_REG_1_YA_OFFSET_L							0x7B
#define TWI1_SLAVE_GYRO_REG_1_ZA_OFFSET_H							0x7D
#define TWI1_SLAVE_GYRO_REG_1_ZA_OFFSET_L							0x7E

#define TWI1_SLAVE_GYRO_ADDR_2										0x0C
#define TWI1_SLAVE_GYRO_REG_2_WIA									0x00
#define TWI1_SLAVE_GYRO_REG_2_INFO									0x01

#define TWI1_SLAVE_GYRO_REG_2_ST1									0x02
#define TWI1_SLAVE_GYRO_DTA_2_ST1__DRDY								0x01
#define TWI1_SLAVE_GYRO_DTA_2_ST1__DOR								0x02

#define TWI1_SLAVE_GYRO_REG_2_HX_L									0x03
#define TWI1_SLAVE_GYRO_REG_2_HX_H									0x04
#define TWI1_SLAVE_GYRO_REG_2_HY_L									0x05
#define TWI1_SLAVE_GYRO_REG_2_HY_H									0x06
#define TWI1_SLAVE_GYRO_REG_2_HZ_L									0x07
#define TWI1_SLAVE_GYRO_REG_2_HZ_Y									0x08

#define TWI1_SLAVE_GYRO_REG_2_ST2									0x09
#define TWI1_SLAVE_GYRO_DTA_2_ST2__HOFL								0x08
#define TWI1_SLAVE_GYRO_DTA_2_ST2__BITM								0x10

#define TWI1_SLAVE_GYRO_REG_2_CNTL1									0x0A
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE0							0x01
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE1							0x02
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE2							0x04
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE3							0x08
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__BIT							0x10
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE_16B_POWER_DOWN			0x10
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE_16B_SINGLE_VAL			0x11
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE_16B_RUN_8HZ_VAL			0x12
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE_16B_RUN_100HZ_VAL			0x16
#define TWI1_SLAVE_GYRO_DTA_2_CNTL1__MODE_PROM_VAL					0x1F

#define TWI1_SLAVE_GYRO_REG_2_CNTL2									0x0B
#define TWI1_SLAVE_GYRO_DTA_2_CNTL2__SRST							0x01

#define TWI1_SLAVE_GYRO_REG_2_ASTC									0x0C

#define TWI1_SLAVE_GYRO_REG_2_I2CDIS								0x0F
#define TWI1_SLAVE_GYRO_REG_2_I2CDIS__DISABLE_VAL					0b00011011

#define TWI1_SLAVE_GYRO_REG_2_ASAX									0x10
#define TWI1_SLAVE_GYRO_REG_2_ASAY									0x11
#define TWI1_SLAVE_GYRO_REG_2_ASAZ									0x12


#define TWI1_SLAVE_BARO_ADDR										0x76
#define TWI1_SLAVE_BARO_REG_RESET									0x1E
#define TWI1_SLAVE_BARO_REG_VERSION									0xAE
#define TWI1_SLAVE_BARO_REG_PROM									0xA0
#define TWI1_SLAVE_BARO_REG_CONV_D1_256								0x40
#define TWI1_SLAVE_BARO_REG_CONV_D1_512								0x42
#define TWI1_SLAVE_BARO_REG_CONV_D1_1024							0x44
#define TWI1_SLAVE_BARO_REG_CONV_D1_2048							0x46
#define TWI1_SLAVE_BARO_REG_CONV_D1_4096							0x48
#define TWI1_SLAVE_BARO_REG_CONV_D2_256								0x50
#define TWI1_SLAVE_BARO_REG_CONV_D2_512								0x52
#define TWI1_SLAVE_BARO_REG_CONV_D2_1024							0x54
#define TWI1_SLAVE_BARO_REG_CONV_D2_2048							0x56
#define TWI1_SLAVE_BARO_REG_CONV_D2_4096							0x58
#define TWI1_SLAVE_BARO_REG_ADC_READ								0x00


#define TWI1_SLAVE_HYGRO_ADDR										0x44

#define TWI1_SLAVE_HYGRO_REG_RESET_HI								0x30
#define TWI1_SLAVE_HYGRO_REG_RESET_LO								0xA2

#define TWI1_SLAVE_HYGRO_REG_STATUS_HI								0xF3
#define TWI1_SLAVE_HYGRO_REG_STATUS_LO								0x2D

#define TWI1_SLAVE_HYGRO_REG_BREAK_HI								0x30
#define TWI1_SLAVE_HYGRO_REG_BREAK_LO								0x93

#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_HIPREC_HI				0x20
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_HIPREC_LO				0x32
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_MEDPREC_HI				0x20
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_MEDPREC_LO				0x24
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_LOPREC_HI				0x20
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_0MPS5_LOPREC_LO				0x2F

#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_HIPREC_HI				0x21
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_HIPREC_LO				0x30
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_MEDPREC_HI				0x21
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_MEDPREC_LO				0x26
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_LOPREC_HI				0x21
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_1MPS_LOPREC_LO				0x2D

#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_HIPREC_HI				0x22
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_HIPREC_LO				0x36
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_MEDPREC_HI				0x22
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_MEDPREC_LO				0x20
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_LOPREC_HI				0x22
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_2MPS_LOPREC_LO				0x2B

#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_HIPREC_HI				0x23
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_HIPREC_LO				0x34
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_MEDPREC_HI				0x23
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_MEDPREC_LO				0x22
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_LOPREC_HI				0x23
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_4MPS_LOPREC_LO				0x29

#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_HIPREC_HI				0x27
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_HIPREC_LO				0x37
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_MEDPREC_HI				0x27
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_MEDPREC_LO				0x21
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_LOPREC_HI				0x27
#define TWI1_SLAVE_HYGRO_REG_PERIODIC_10MPS_LOPREC_LO				0x2A

#define TWI1_SLAVE_HYGRO_REG_ONESHOT_HIPREC_NOCLKSTRETCH_HI			0x24
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_HIPREC_NOCLKSTRETCH_LO			0x00
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_MIDPREC_NOCLKSTRETCH_HI		0x24
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_MIDPREC_NOCLKSTRETCH_LO		0x0B
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_LOPREC_NOCLKSTRETCH_HI			0x24
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_LOPREC_NOCLKSTRETCH_LO			0x16

#define TWI1_SLAVE_HYGRO_REG_ONESHOT_HIPREC_CLKSTRETCH_HI			0x2C
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_HIPREC_CLKSTRETCH_LO			0x06
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_MIDPREC_CLKSTRETCH_HI			0x2C
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_MIDPREC_CLKSTRETCH_LO			0x0D
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_LOPREC_CLKSTRETCH_HI			0x2C
#define TWI1_SLAVE_HYGRO_REG_ONESHOT_LOPREC_CLKSTRETCH_LO			0x10


#define TWI1_SLAVE_HYGRO_REG_FETCH_DATA_HI							0xE0
#define TWI1_SLAVE_HYGRO_REG_FETCH_DATA_LO							0x00


#define TWI2_MASTER													TWIC
//#define TWI2_SLAVE												TWIC
#define TWI2_MASTER_PORT											PORTC
#define TWI2_MASTER_ADDR											0x20
#define TWI2_SLAVE_ADDR												TWI_SMART_LCD_ADDR
#define TWI2_SPEED													400000
#define TWI2_STR_MAXLEN												6
#define TWI2_DISPLAY_TIMEOUT_MS										50U

/* Buffer size defines */
#define TWIS_RECEIVE_BUFFER_SIZE									8
#define TWIS_SEND_BUFFER_SIZE										8
#define TWI_DATA_LENGTH												(max(TWIS_RECEIVE_BUFFER_SIZE, TWIS_SEND_BUFFER_SIZE))

/* Baud register setting calculation. Formula described in datasheet */
#define TWI_BAUD(F_SYS, F_TWI)										((F_SYS / (2 * F_TWI)) - 5)


typedef enum TWI_MASTER_FSM_STATE {
	TWI_MASTER_FSM_STATE_NOOP			= 0x00,

	TWI_MASTER_FSM_STATE__TX_CHIP		= 0x01,
	TWI_MASTER_FSM_STATE__TX_ADDR		= 0x02,
	TWI_MASTER_FSM_STATE__TX_DATA		= 0x03,

	TWI_MASTER_FSM_STATE__TX_RX_SR		= 0x08,
	TWI_MASTER_FSM_STATE__RX_CHIP		= 0x09,
	TWI_MASTER_FSM_STATE__RX_DATA		= 0x0A,
} TWI_MASTER_FSM_STATE_t;


typedef enum TWI_SLAVE_FSM_STATE {
	TWI_SLAVE_FSM_STATE_NOOP			= 0x00,
} TWI_SLAVE_FSM_STATE_t;


/* Input parameters when initializing the TWI module mode */
typedef struct twi_options {
	/* INIT MASTER/SLAVE */
	TWI_t							   *ifc;										// Pointer to what interface to use
	uint32_t							speed;										// baud rate of the TWI bus

	/* INIT SLAVE only */
	uint8_t								ownChip;									// SLAVE mode: own chip address
} twi_options_t;

/* Information concerning the data transmission */
typedef struct TWI_Master_Transaction {
	register8_t							destChip;									// TWI chip address to communicate with
	register8_t							addr[3];									// TWI address/commands to issue to the other chip (node)
	register8_t							addrLength;									// length of the TWI data address segment (1-3 bytes)

	register8_t							bytesToSend;								// how many bytes to write
	register8_t							bytesToReceive;								// how many bytes do we want to read
	register8_t						    data[TWI_DATA_LENGTH];						// data to be sent or received
} TWI_Master_Transaction_t;


/* TWI slave driver struct */
typedef struct TWI_Master {
	TWI_t							   *ifc;										// Pointer to what interface to use
	register8_t							lock;										// Zero means unlocked
	volatile TWI_MASTER_FSM_STATE_t		state;										// FSM state

	register8_t							destChip;									// TWI chip address to communicate with
	register8_t							addr[3];									// TWI address/commands to issue to the other chip (node)
	register8_t							addrLength;									// length of the TWI data address segment (1-3 bytes)
	register8_t							addrIdx;									// Current transmit position of the address field

	register8_t							bytesTx;									// Number of bytes to be sent
	register8_t							bytesTxIdx;									// Current transmit position of the data field
	register8_t							bytesRx;									// Number of bytes received
	register8_t							bytesRxIdx;									// Current receive position of the data field

	register8_t							status;										// Last status of transaction
	register8_t							result;										// Last result of transaction
	volatile bool						abort;										// Strobe to abort

	register8_t							dataTx[TWIS_SEND_BUFFER_SIZE];				// Data to write
	register8_t							dataRx[TWIS_RECEIVE_BUFFER_SIZE];			// Read data
} TWI_Master_t;


/* TWI slave driver struct */
typedef struct TWI_Slave {
	TWI_t							   *ifc;										// Pointer to what interface to use
	register8_t							lock;										// Zero means unlocked
    volatile TWI_SLAVE_FSM_STATE_t		state;										// FSM state

	void								(*Process_Data) (void);						// Pointer to process data function

	register8_t							bytesRx;									// Number of bytes received
	register8_t							bytesTx;									// Number of bytes sent

	register8_t							status;										// Status of transaction
	volatile status_code_t				result;										// Result of transaction
	volatile bool						abort;										// Strobe to abort

	register8_t							dataReceived[TWIS_RECEIVE_BUFFER_SIZE];		// Read data
	register8_t							dataToSend[TWIS_SEND_BUFFER_SIZE];			// Data to write
} TWI_Slave_t;


int16_t calc_gyro1_accel_raw2mg(int16_t raw, int16_t factor);

void isr_twi_masters(TWI_Master_t *twi_m);
void isr_twi_slaves(TWI_Slave_t *twi_s);

status_code_t twi_master_init(TWI_Master_t *ifcCtx, const twi_options_t *opt);
void twi_master_shutdown(TWI_Master_t *ifcCtx);

/* Enable Master Mode of the TWI */
static inline void twi_master_enable(TWI_Master_t *ifcCtx)
{
  ifcCtx->ifc->MASTER.CTRLA |= TWI_MASTER_ENABLE_bm;
}

/* Disable Master Mode of the TWI */
static inline void twi_master_disable(TWI_Master_t *ifcCtx)
{
  ifcCtx->ifc->MASTER.CTRLA &= (~TWI_MASTER_ENABLE_bm);
}

status_code_t twi_master_start_transaction(TWI_Master_t *ifcCtx, TWI_Master_Transaction_t *ta);

bool twi2_waitUntilReady(bool retry);

void twi2_set_leds(uint8_t leds);
void twi2_set_ledbl(uint8_t mode, uint8_t pwm_p100);
void twi2_set_bias(uint8_t bias);
void twi2_set_beep(uint8_t pitch_10hz, uint8_t len_10ms);

void twi_init(void);
void twi_start(void);

bool service_twi1_gyro(bool sync);

void isr_10ms_twi1_onboard(void);
void isr_100ms_twi1_onboard(void);
void isr_500ms_twi1_onboard(void);
void isr_sparetime_twi1_onboard(void);

status_code_t twi1_gyro_gyro_offset_set(void);
status_code_t twi1_gyro_accel_offset_set(void);
void init_twi1_gyro(void);
void task_twi1_gyro(void);
// void task_twi1_onboard(void);
void start_twi2_lcd(void);

void task_twi2_lcd_reset(void);
void task_twi2_lcd_cls(void);
void task_twi2_lcd_pos_xy(uint8_t x, uint8_t y);
void task_twi2_lcd_str(uint8_t x, uint8_t y, const char* str);
void task_twi2_lcd_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void task_twi2_lcd_rect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, bool filled, uint8_t color);
void task_twi2_lcd_circ(uint8_t x, uint8_t y, uint8_t radius, bool filled, uint8_t color);
void task_twi2_lcd_header(void);

void task_twi2_lcd__cpu1(uint8_t col_left);
void task_twi2_lcd__cpu2(uint8_t col_left);
void task_twi2_lcd__sim1(uint8_t col_left);
void task_twi2_lcd__hygro(uint8_t col_left);
void task_twi2_lcd__gyro_gfxmag(void);
void task_twi2_lcd__gyro_gfxaccel(void);
void task_twi2_lcd__gyro_gfxgyro(void);
void task_twi2_lcd__gyro_beepvario(void);
void task_twi2_lcd__gyro(void);
void task_twi2_lcd__baro(uint8_t col_left);
void task_twi2_lcd__environment(uint8_t col_left);
void task_twi2_lcd_print_format_P(uint8_t x, uint8_t y, const char* fmt_P);
// void task_twi2_lcd(void);

void task_twi(void);


#endif /* TWI_H_ */
