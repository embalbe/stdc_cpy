/*
 ******************************************************************************
 * @file    lis3de_reg.h
 * @author  Sensors Software Solution Team
 * @brief   This file contains all the functions prototypes for the
 *          lis3de_reg.c driver.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LIS3DE_REGS_H
#define LIS3DE_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup LIS3DE
  * @{
  *
  */

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */

/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7       : 1;
  uint8_t bit6       : 1;
  uint8_t bit5       : 1;
  uint8_t bit4       : 1;
  uint8_t bit3       : 1;
  uint8_t bit2       : 1;
  uint8_t bit1       : 1;
  uint8_t bit0       : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, uint8_t *,
                                    uint16_t);
typedef int32_t (*stmdev_read_ptr) (void *, uint8_t, uint8_t *,
                                    uint16_t);

typedef struct {
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Customizable optional pointer **/
  void *handle;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** @defgroup    Generic address-data structure definition
  * @brief       This structure is useful to load a predefined configuration
  *              of a sensor.
  *              You can create a sensor configuration by your own or using
  *              Unico / Unicleo tools available on STMicroelectronics
  *              web site.
  *
  * @{
  *
  */

typedef struct {
  uint8_t address;
  uint8_t data;
} ucf_line_t;

/**
  * @}
  *
  */

#endif /* MEMS_UCF_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup LIS3DE_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format if SA0=0 -> 31 if SA0=1 -> 33 **/
#define LIS3DE_I2C_ADD_L   0x31U
#define LIS3DE_I2C_ADD_H   0x33U

/** Device Identification (Who am I) **/
#define LIS3DE_ID          0x33U

/**
  * @}
  *
  */

#define LIS3DE_STATUS_REG_AUX        0x07U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t _1da              : 1;
  uint8_t _2da              : 1;
  uint8_t _3da              : 1;
  uint8_t _321da            : 1;
  uint8_t _1or              : 1;
  uint8_t _2or              : 1;
  uint8_t _3or              : 1;
  uint8_t _321or            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t _321or            : 1;
  uint8_t _3or              : 1;
  uint8_t _2or              : 1;
  uint8_t _1or              : 1;
  uint8_t _321da            : 1;
  uint8_t _3da              : 1;
  uint8_t _2da              : 1;
  uint8_t _1da              : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_status_reg_aux_t;

#define LIS3DE_OUT_ADC1_L            0x08U
#define LIS3DE_OUT_ADC1_H            0x09U
#define LIS3DE_OUT_ADC2_L            0x0AU
#define LIS3DE_OUT_ADC2_H            0x0BU
#define LIS3DE_OUT_ADC3_L            0x0CU
#define LIS3DE_OUT_ADC3_H            0x0DU
#define LIS3DE_INT_COUNTER_REG       0x0EU
#define LIS3DE_WHO_AM_I              0x0FU

#define LIS3DE_TEMP_CFG_REG          0x1FU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01       : 6;
  uint8_t adc_pd            : 1;
  uint8_t temp_en           : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t temp_en           : 1;
  uint8_t adc_pd            : 1;
  uint8_t not_used_01       : 6;
#endif /* DRV_BYTE_ORDER */
} lis3de_temp_cfg_reg_t;

#define LIS3DE_CTRL_REG1             0x20U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xen               : 1;
  uint8_t yen               : 1;
  uint8_t zen               : 1;
  uint8_t lpen              : 1;
  uint8_t odr               : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t odr               : 4;
  uint8_t lpen              : 1;
  uint8_t zen               : 1;
  uint8_t yen               : 1;
  uint8_t xen               : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg1_t;

#define LIS3DE_CTRL_REG2             0x21U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t hp                : 3; /* HPCLICK + HP_IA2 + HP_IA1 -> HP */
  uint8_t fds               : 1;
  uint8_t hpcf              : 2;
  uint8_t hpm               : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hpm               : 2;
  uint8_t hpcf              : 2;
  uint8_t fds               : 1;
  uint8_t hp                : 3; /* HPCLICK + HP_IA2 + HP_IA1 -> HP */
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg2_t;

#define LIS3DE_CTRL_REG3             0x22U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t int1_overrun      : 1;
  uint8_t int1_wtm          : 1;
  uint8_t int1_drdy2        : 1;
  uint8_t int1_drdy1        : 1;
  uint8_t int1_ig2          : 1;
  uint8_t int1_ig1          : 1;
  uint8_t int1_click        : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_click        : 1;
  uint8_t int1_ig1          : 1;
  uint8_t int1_ig2          : 1;
  uint8_t int1_drdy1        : 1;
  uint8_t int1_drdy2        : 1;
  uint8_t int1_wtm          : 1;
  uint8_t int1_overrun      : 1;
  uint8_t not_used_01       : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg3_t;

#define LIS3DE_CTRL_REG4             0x23U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sim               : 1;
  uint8_t st                : 2;
  uint8_t not_used_01       : 1;
  uint8_t fs                : 2;
  uint8_t not_used_02       : 1;
  uint8_t bdu               : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bdu               : 1;
  uint8_t not_used_02       : 1;
  uint8_t fs                : 2;
  uint8_t not_used_01       : 1;
  uint8_t st                : 2;
  uint8_t sim               : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg4_t;

#define LIS3DE_CTRL_REG5             0x24U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d4d_ig2           : 1;
  uint8_t lir_ig2           : 1;
  uint8_t d4d_ig1           : 1;
  uint8_t lir_ig1           : 1;
  uint8_t not_used_01       : 2;
  uint8_t fifo_en           : 1;
  uint8_t boot              : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot              : 1;
  uint8_t fifo_en           : 1;
  uint8_t not_used_01       : 2;
  uint8_t lir_ig1           : 1;
  uint8_t d4d_ig1           : 1;
  uint8_t lir_ig2           : 1;
  uint8_t d4d_ig2           : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg5_t;

#define LIS3DE_CTRL_REG6             0x25U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t h_lactive         : 1;
  uint8_t not_used_02       : 1;
  uint8_t int2_act          : 1;
  uint8_t int2_boot         : 1;
  uint8_t int2_ig2          : 1;
  uint8_t int2_ig1          : 1;
  uint8_t int2_click        : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_click        : 1;
  uint8_t int2_ig1          : 1;
  uint8_t int2_ig2          : 1;
  uint8_t int2_boot         : 1;
  uint8_t int2_act          : 1;
  uint8_t not_used_02       : 1;
  uint8_t h_lactive         : 1;
  uint8_t not_used_01       : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ctrl_reg6_t;

#define LIS3DE_REFERENCE             0x26U
#define LIS3DE_STATUS_REG            0x27U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xda               : 1;
  uint8_t yda               : 1;
  uint8_t zda               : 1;
  uint8_t zyxda             : 1;
  uint8_t _xor              : 1;
  uint8_t yor               : 1;
  uint8_t zor               : 1;
  uint8_t zyxor             : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t zyxor             : 1;
  uint8_t zor               : 1;
  uint8_t yor               : 1;
  uint8_t _xor              : 1;
  uint8_t zyxda             : 1;
  uint8_t zda               : 1;
  uint8_t yda               : 1;
  uint8_t xda               : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_status_reg_t;

#define LIS3DE_OUT_X                 0x29U
#define LIS3DE_OUT_Y                 0x2BU
#define LIS3DE_OUT_Z                 0x2DU
#define LIS3DE_FIFO_CTRL_REG         0x2EU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fth               : 5;
  uint8_t tr                : 1;
  uint8_t fm                : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fm                : 2;
  uint8_t tr                : 1;
  uint8_t fth               : 5;
#endif /* DRV_BYTE_ORDER */
} lis3de_fifo_ctrl_reg_t;

#define LIS3DE_FIFO_SRC_REG          0x2FU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fss               : 5;
  uint8_t empty             : 1;
  uint8_t ovrn_fifo         : 1;
  uint8_t wtm               : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t wtm               : 1;
  uint8_t ovrn_fifo         : 1;
  uint8_t empty             : 1;
  uint8_t fss               : 5;
#endif /* DRV_BYTE_ORDER */
} lis3de_fifo_src_reg_t;

#define LIS3DE_IG1_CFG               0x30U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xlie              : 1;
  uint8_t xhie              : 1;
  uint8_t ylie              : 1;
  uint8_t yhie              : 1;
  uint8_t zlie              : 1;
  uint8_t zhie              : 1;
  uint8_t _6d               : 1;
  uint8_t aoi               : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t aoi               : 1;
  uint8_t _6d               : 1;
  uint8_t zhie              : 1;
  uint8_t zlie              : 1;
  uint8_t yhie              : 1;
  uint8_t ylie              : 1;
  uint8_t xhie              : 1;
  uint8_t xlie              : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig1_cfg_t;

#define LIS3DE_IG1_SOURCE            0x31U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl                : 1;
  uint8_t xh                : 1;
  uint8_t yl                : 1;
  uint8_t yh                : 1;
  uint8_t zl                : 1;
  uint8_t zh                : 1;
  uint8_t ia                : 1;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t ia                : 1;
  uint8_t zh                : 1;
  uint8_t zl                : 1;
  uint8_t yh                : 1;
  uint8_t yl                : 1;
  uint8_t xh                : 1;
  uint8_t xl                : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig1_source_t;

#define LIS3DE_IG1_THS               0x32U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths               : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t ths               : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig1_ths_t;

#define LIS3DE_IG1_DURATION          0x33U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d                 : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t d                 : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig1_duration_t;

#define LIS3DE_IG2_CFG               0x34U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xlie              : 1;
  uint8_t xhie              : 1;
  uint8_t ylie              : 1;
  uint8_t yhie              : 1;
  uint8_t zlie              : 1;
  uint8_t zhie              : 1;
  uint8_t _6d               : 1;
  uint8_t aoi               : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t aoi               : 1;
  uint8_t _6d               : 1;
  uint8_t zhie              : 1;
  uint8_t zlie              : 1;
  uint8_t yhie              : 1;
  uint8_t ylie              : 1;
  uint8_t xhie              : 1;
  uint8_t xlie              : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig2_cfg_t;

#define LIS3DE_IG2_SOURCE            0x35U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl                : 1;
  uint8_t xh                : 1;
  uint8_t yl                : 1;
  uint8_t yh                : 1;
  uint8_t zl                : 1;
  uint8_t zh                : 1;
  uint8_t ia                : 1;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t ia                : 1;
  uint8_t zh                : 1;
  uint8_t zl                : 1;
  uint8_t yh                : 1;
  uint8_t yl                : 1;
  uint8_t xh                : 1;
  uint8_t xl                : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig2_source_t;

#define LIS3DE_IG2_THS               0x36U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths               : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t ths               : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig2_ths_t;

#define LIS3DE_IG2_DURATION          0x37U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d                 : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t d                 : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_ig2_duration_t;

#define LIS3DE_CLICK_CFG             0x38U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xs                : 1;
  uint8_t xd                : 1;
  uint8_t ys                : 1;
  uint8_t yd                : 1;
  uint8_t zs                : 1;
  uint8_t zd                : 1;
  uint8_t not_used_01       : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 2;
  uint8_t zd                : 1;
  uint8_t zs                : 1;
  uint8_t yd                : 1;
  uint8_t ys                : 1;
  uint8_t xd                : 1;
  uint8_t xs                : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_click_cfg_t;

#define LIS3DE_CLICK_SRC             0x39U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t x                 : 1;
  uint8_t y                 : 1;
  uint8_t z                 : 1;
  uint8_t sign              : 1;
  uint8_t sclick            : 1;
  uint8_t dclick            : 1;
  uint8_t ia                : 1;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t ia                : 1;
  uint8_t dclick            : 1;
  uint8_t sclick            : 1;
  uint8_t sign              : 1;
  uint8_t z                 : 1;
  uint8_t y                 : 1;
  uint8_t x                 : 1;
#endif /* DRV_BYTE_ORDER */
} lis3de_click_src_t;

#define LIS3DE_CLICK_THS             0x3AU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths               : 7;
  uint8_t lir               : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t lir               : 1;
  uint8_t ths               : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_click_ths_t;

#define LIS3DE_TIME_LIMIT            0x3BU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t tli               : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t tli               : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_time_limit_t;

#define LIS3DE_TIME_LATENCY          0x3CU
typedef struct {
  uint8_t tla               : 8;
} lis3de_time_latency_t;

#define LIS3DE_TIME_WINDOW           0x3DU
typedef struct {
  uint8_t tw                : 8;
} lis3de_time_window_t;

#define LIS3DE_ACT_THS               0x3EU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t acth              : 7;
  uint8_t not_used_01       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01       : 1;
  uint8_t acth              : 7;
#endif /* DRV_BYTE_ORDER */
} lis3de_act_ths_t;

#define LIS3DE_ACT_DUR               0x3FU
typedef struct {
  uint8_t actd              : 8;
} lis3de_act_dur_t;

/**
  * @defgroup LIS3DE_Register_Union
  * @brief    This union group all the registers that has a bitfield
  *           description.
  *           This union is useful but not need by the driver.
  *
  *           REMOVING this union you are compliant with:
  *           MISRA-C 2012 [Rule 19.2] -> " Union are not allowed "
  *
  * @{
  *
  */
typedef union {
  lis3de_status_reg_aux_t status_reg_aux;
  lis3de_temp_cfg_reg_t   temp_cfg_reg;
  lis3de_ctrl_reg1_t      ctrl_reg1;
  lis3de_ctrl_reg2_t      ctrl_reg2;
  lis3de_ctrl_reg3_t      ctrl_reg3;
  lis3de_ctrl_reg4_t      ctrl_reg4;
  lis3de_ctrl_reg5_t      ctrl_reg5;
  lis3de_ctrl_reg6_t      ctrl_reg6;
  lis3de_status_reg_t     status_reg;
  lis3de_fifo_ctrl_reg_t  fifo_ctrl_reg;
  lis3de_fifo_src_reg_t   fifo_src_reg;
  lis3de_ig1_cfg_t        int1_cfg;
  lis3de_ig1_source_t     int1_src;
  lis3de_ig1_ths_t        int1_ths;
  lis3de_ig1_duration_t   int1_duration;
  lis3de_ig2_cfg_t        int2_cfg;
  lis3de_ig2_source_t     int2_src;
  lis3de_ig2_ths_t        int2_ths;
  lis3de_ig2_duration_t   int2_duration;
  lis3de_click_cfg_t      click_cfg;
  lis3de_click_src_t      click_src;
  lis3de_click_ths_t      click_ths;
  lis3de_time_limit_t     time_limit;
  lis3de_time_latency_t   time_latency;
  lis3de_time_window_t    time_window;
  lis3de_act_ths_t        act_ths;
  lis3de_act_dur_t        act_dur;
  bitwise_t               bitwise;
  uint8_t                 byte;
} lis3de_reg_t;

/**
  * @}
  *
  */

int32_t lis3de_read_reg(stmdev_ctx_t *ctx, uint8_t reg, uint8_t *data,
                        uint16_t len);
int32_t lis3de_write_reg(stmdev_ctx_t *ctx, uint8_t reg,
                         uint8_t *data,
                         uint16_t len);

float lis3de_from_fs2_to_mg(int16_t lsb);
float lis3de_from_fs4_to_mg(int16_t lsb);
float lis3de_from_fs8_to_mg(int16_t lsb);
float lis3de_from_fs16_to_mg(int16_t lsb);
float lis3de_from_lsb_to_celsius(int16_t lsb);

int32_t lis3de_temp_status_reg_get(stmdev_ctx_t *ctx, uint8_t *buff);
int32_t lis3de_temp_data_ready_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_temp_data_ovr_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_temperature_raw_get(stmdev_ctx_t *ctx, uint8_t *buff);
int32_t lis3de_adc_raw_get(stmdev_ctx_t *ctx, int16_t *val);

typedef enum {
  LIS3DE_AUX_DISABLE          = 0,
  LIS3DE_AUX_ON_TEMPERATURE   = 3,
  LIS3DE_AUX_ON_PADS          = 1,
} lis3de_temp_en_t;
int32_t lis3de_aux_adc_set(stmdev_ctx_t *ctx, lis3de_temp_en_t val);
int32_t lis3de_aux_adc_get(stmdev_ctx_t *ctx, lis3de_temp_en_t *val);

typedef enum {
  LIS3DE_NM    = 0,
  LIS3DE_LP    = 1,
} lis3de_op_md_t;
int32_t lis3de_operating_mode_set(stmdev_ctx_t *ctx,
                                  lis3de_op_md_t val);
int32_t lis3de_operating_mode_get(stmdev_ctx_t *ctx,
                                  lis3de_op_md_t *val);

typedef enum {
  LIS3DE_POWER_DOWN                      = 0x00,
  LIS3DE_ODR_1Hz                         = 0x01,
  LIS3DE_ODR_10Hz                        = 0x02,
  LIS3DE_ODR_25Hz                        = 0x03,
  LIS3DE_ODR_50Hz                        = 0x04,
  LIS3DE_ODR_100Hz                       = 0x05,
  LIS3DE_ODR_200Hz                       = 0x06,
  LIS3DE_ODR_400Hz                       = 0x07,
  LIS3DE_ODR_1kHz6                       = 0x08,
  LIS3DE_ODR_5kHz376_LP_1kHz344_NM       = 0x09,
} lis3de_odr_t;
int32_t lis3de_data_rate_set(stmdev_ctx_t *ctx, lis3de_odr_t val);
int32_t lis3de_data_rate_get(stmdev_ctx_t *ctx, lis3de_odr_t *val);

int32_t lis3de_high_pass_on_outputs_set(stmdev_ctx_t *ctx,
                                        uint8_t val);
int32_t lis3de_high_pass_on_outputs_get(stmdev_ctx_t *ctx,
                                        uint8_t *val);

typedef enum {
  LIS3DE_AGGRESSIVE  = 0,
  LIS3DE_STRONG      = 1,
  LIS3DE_MEDIUM      = 2,
  LIS3DE_LIGHT       = 3,
} lis3de_hpcf_t;
int32_t lis3de_high_pass_bandwidth_set(stmdev_ctx_t *ctx,
                                       lis3de_hpcf_t val);
int32_t lis3de_high_pass_bandwidth_get(stmdev_ctx_t *ctx,
                                       lis3de_hpcf_t *val);

typedef enum {
  LIS3DE_NORMAL_WITH_RST  = 0,
  LIS3DE_REFERENCE_MODE   = 1,
  LIS3DE_NORMAL           = 2,
  LIS3DE_AUTORST_ON_INT   = 3,
} lis3de_hpm_t;
int32_t lis3de_high_pass_mode_set(stmdev_ctx_t *ctx,
                                  lis3de_hpm_t val);
int32_t lis3de_high_pass_mode_get(stmdev_ctx_t *ctx,
                                  lis3de_hpm_t *val);

typedef enum {
  LIS3DE_2g   = 0,
  LIS3DE_4g   = 1,
  LIS3DE_8g   = 2,
  LIS3DE_16g  = 3,
} lis3de_fs_t;
int32_t lis3de_full_scale_set(stmdev_ctx_t *ctx, lis3de_fs_t val);
int32_t lis3de_full_scale_get(stmdev_ctx_t *ctx, lis3de_fs_t *val);

int32_t lis3de_block_data_update_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_block_data_update_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_filter_reference_set(stmdev_ctx_t *ctx, uint8_t *buff);
int32_t lis3de_filter_reference_get(stmdev_ctx_t *ctx, uint8_t *buff);

int32_t lis3de_xl_data_ready_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_xl_data_ovr_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_acceleration_raw_get(stmdev_ctx_t *ctx, int16_t *buff);

int32_t lis3de_device_id_get(stmdev_ctx_t *ctx, uint8_t *buff);

typedef enum {
  LIS3DE_ST_DISABLE   = 0,
  LIS3DE_ST_POSITIVE  = 1,
  LIS3DE_ST_NEGATIVE  = 2,
} lis3de_st_t;
int32_t lis3de_self_test_set(stmdev_ctx_t *ctx, lis3de_st_t val);
int32_t lis3de_self_test_get(stmdev_ctx_t *ctx, lis3de_st_t *val);

int32_t lis3de_boot_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_boot_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_status_get(stmdev_ctx_t *ctx,
                          lis3de_status_reg_t *val);

int32_t lis3de_int1_gen_conf_set(stmdev_ctx_t *ctx,
                                 lis3de_ig1_cfg_t *val);
int32_t lis3de_int1_gen_conf_get(stmdev_ctx_t *ctx,
                                 lis3de_ig1_cfg_t *val);

int32_t lis3de_int1_gen_source_get(stmdev_ctx_t *ctx,
                                   lis3de_ig1_source_t *val);

int32_t lis3de_int1_gen_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int1_gen_threshold_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lis3de_int1_gen_duration_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int1_gen_duration_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_int2_gen_conf_set(stmdev_ctx_t *ctx,
                                 lis3de_ig2_cfg_t *val);
int32_t lis3de_int2_gen_conf_get(stmdev_ctx_t *ctx,
                                 lis3de_ig2_cfg_t *val);

int32_t lis3de_int2_gen_source_get(stmdev_ctx_t *ctx,
                                   lis3de_ig2_source_t *val);

int32_t lis3de_int2_gen_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int2_gen_threshold_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lis3de_int2_gen_duration_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int2_gen_duration_get(stmdev_ctx_t *ctx, uint8_t *val);

typedef enum {
  LIS3DE_DISC_FROM_INT_GENERATOR  = 0,
  LIS3DE_ON_INT1_GEN              = 1,
  LIS3DE_ON_INT2_GEN              = 2,
  LIS3DE_ON_TAP_GEN               = 4,
  LIS3DE_ON_INT1_INT2_GEN         = 3,
  LIS3DE_ON_INT1_TAP_GEN          = 5,
  LIS3DE_ON_INT2_TAP_GEN          = 6,
  LIS3DE_ON_INT1_INT2_TAP_GEN     = 7,
} lis3de_hp_t;
int32_t lis3de_high_pass_int_conf_set(stmdev_ctx_t *ctx,
                                      lis3de_hp_t val);
int32_t lis3de_high_pass_int_conf_get(stmdev_ctx_t *ctx,
                                      lis3de_hp_t *val);

int32_t lis3de_pin_int1_config_set(stmdev_ctx_t *ctx,
                                   lis3de_ctrl_reg3_t *val);
int32_t lis3de_pin_int1_config_get(stmdev_ctx_t *ctx,
                                   lis3de_ctrl_reg3_t *val);

int32_t lis3de_int2_pin_detect_4d_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int2_pin_detect_4d_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

typedef enum {
  LIS3DE_INT2_PULSED   = 0,
  LIS3DE_INT2_LATCHED  = 1,
} lis3de_lir_int2_t;
int32_t lis3de_int2_pin_notification_mode_set(stmdev_ctx_t *ctx,
                                              lis3de_lir_int2_t val);
int32_t lis3de_int2_pin_notification_mode_get(stmdev_ctx_t *ctx,
                                              lis3de_lir_int2_t *val);

int32_t lis3de_int1_pin_detect_4d_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_int1_pin_detect_4d_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

typedef enum {
  LIS3DE_INT1_PULSED   = 0,
  LIS3DE_INT1_LATCHED  = 1,
} lis3de_lir_int1_t;
int32_t lis3de_int1_pin_notification_mode_set(stmdev_ctx_t *ctx,
                                              lis3de_lir_int1_t val);
int32_t lis3de_int1_pin_notification_mode_get(stmdev_ctx_t *ctx,
                                              lis3de_lir_int1_t *val);

int32_t lis3de_pin_int2_config_set(stmdev_ctx_t *ctx,
                                   lis3de_ctrl_reg6_t *val);
int32_t lis3de_pin_int2_config_get(stmdev_ctx_t *ctx,
                                   lis3de_ctrl_reg6_t *val);

int32_t lis3de_fifo_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_fifo_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_fifo_watermark_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_fifo_watermark_get(stmdev_ctx_t *ctx, uint8_t *val);

typedef enum {
  LIS3DE_INT1_GEN = 0,
  LIS3DE_INT2_GEN = 1,
} lis3de_tr_t;
int32_t lis3de_fifo_trigger_event_set(stmdev_ctx_t *ctx,
                                      lis3de_tr_t val);
int32_t lis3de_fifo_trigger_event_get(stmdev_ctx_t *ctx,
                                      lis3de_tr_t *val);

typedef enum {
  LIS3DE_BYPASS_MODE           = 0,
  LIS3DE_FIFO_MODE             = 1,
  LIS3DE_DYNAMIC_STREAM_MODE   = 2,
  LIS3DE_STREAM_TO_FIFO_MODE   = 3,
} lis3de_fm_t;
int32_t lis3de_fifo_mode_set(stmdev_ctx_t *ctx, lis3de_fm_t val);
int32_t lis3de_fifo_mode_get(stmdev_ctx_t *ctx, lis3de_fm_t *val);

int32_t lis3de_fifo_status_get(stmdev_ctx_t *ctx,
                               lis3de_fifo_src_reg_t *val);

int32_t lis3de_fifo_data_level_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_fifo_empty_flag_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_fifo_ovr_flag_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_fifo_fth_flag_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_tap_conf_set(stmdev_ctx_t *ctx,
                            lis3de_click_cfg_t *val);
int32_t lis3de_tap_conf_get(stmdev_ctx_t *ctx,
                            lis3de_click_cfg_t *val);

int32_t lis3de_tap_source_get(stmdev_ctx_t *ctx,
                              lis3de_click_src_t *val);

int32_t lis3de_tap_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_tap_threshold_get(stmdev_ctx_t *ctx, uint8_t *val);

typedef enum {
  LIS3DE_TAP_PULSED   = 0,
  LIS3DE_TAP_LATCHED  = 1,
} lis3de_lir_t;
int32_t lis3de_tap_notification_mode_set(stmdev_ctx_t *ctx,
                                         lis3de_lir_t val);
int32_t lis3de_tap_notification_mode_get(stmdev_ctx_t *ctx,
                                         lis3de_lir_t *val);

int32_t lis3de_shock_dur_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_shock_dur_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_quiet_dur_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_quiet_dur_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_double_tap_timeout_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_double_tap_timeout_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lis3de_act_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_act_threshold_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lis3de_act_timeout_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lis3de_act_timeout_get(stmdev_ctx_t *ctx, uint8_t *val);

typedef enum {
  LIS3DE_SPI_4_WIRE = 0,
  LIS3DE_SPI_3_WIRE = 1,
} lis3de_sim_t;
int32_t lis3de_spi_mode_set(stmdev_ctx_t *ctx, lis3de_sim_t val);
int32_t lis3de_spi_mode_get(stmdev_ctx_t *ctx, lis3de_sim_t *val);

/**
  * @}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* LIS3DE_REGS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
