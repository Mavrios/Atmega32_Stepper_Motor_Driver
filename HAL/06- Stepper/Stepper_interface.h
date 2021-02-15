/*
 * Stepper_interface.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Kishk
 */

#ifndef HAL_06__STEPPER_STEPPER_INTERFACE_H_
#define HAL_06__STEPPER_STEPPER_INTERFACE_H_

#define Stepper_u8FullStep				1
#define Stepper_u8HalfStep				2
#define Stepper_u8CW					1
#define Stepper_u8CCW					2

#define Stepper_u8LowSpeed				5
#define Stepper_u8MediumSpeed			3
#define Stepper_u8FastSpeed				2
#define Stepper_u8VeryFastSpeed			1


#define Stepper_u8DegreeToSteps(Degree)			( Degree  * (512.0 / 360.0))



void Stepper_voidInit(void);
void Stepper_voidOff(void);
void Stepper_voidOn(u8 Copy_u8Mode ,u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree);

#endif /* HAL_06__STEPPER_STEPPER_INTERFACE_H_ */
