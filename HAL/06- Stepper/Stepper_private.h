/*
 * Stepper_private.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Kishk
 */

#ifndef HAL_06__STEPPER_STEPPER_PRIVATE_H_
#define HAL_06__STEPPER_STEPPER_PRIVATE_H_


#define STEPPER_u8PinNum	4
static u8 Stepper_u8ArrPin [STEPPER_u8PinNum] = {STEPPER_u8_BLUE_COIL , STEPPER_u8_PINK_COIL , STEPPER_u8_YELLOW_COIL , STEPPER_u8_ORANGE_COIL};

static void Stepper_voidReset(void);
static void Stepper_voidHalf(u8 Copy_u8Speed , u8 Copy_u8Direction);
static u8 Stepper_u8Iterator = 0;
static u16 Stepper_u16Iterator2 = 0;
#endif /* HAL_06__STEPPER_STEPPER_PRIVATE_H_ */
