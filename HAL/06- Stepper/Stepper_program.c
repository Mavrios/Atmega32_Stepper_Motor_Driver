/*
 * Stepper_program.c
 *
 *  Created on: Feb 14, 2021
 *      Author: Kishk
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "util/delay.h"

#include "../../MCAL/01-DIO/DIO_interface.h"
#include "Stepper_interface.h"
#include "Stepper_config.h"
#include "Stepper_private.h"

void Stepper_voidInit(void) {
	DIO_enumSetPinDirection(STEPPER_u8_BLUE_COIL, DIO_OUTPUT);
	DIO_enumSetPinDirection(STEPPER_u8_PINK_COIL, DIO_OUTPUT);
	DIO_enumSetPinDirection(STEPPER_u8_YELLOW_COIL, DIO_OUTPUT);
	DIO_enumSetPinDirection(STEPPER_u8_ORANGE_COIL, DIO_OUTPUT);

	DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_LOW);
}

void Stepper_voidOff(void) {
	DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_LOW);
}
void Stepper_voidOn(u8 Copy_u8Mode, u8 Copy_u8Direction, u8 Copy_u8Speed,
		u16 Copy_u16Degree) {
	if (Copy_u8Mode == Stepper_u8FullStep) {
		if (Copy_u8Direction == Stepper_u8CW) {
			for (Stepper_u16Iterator2 = 0;
					Stepper_u16Iterator2
							< Stepper_u8DegreeToSteps(Copy_u16Degree);
					Stepper_u16Iterator2++) {

				for (Stepper_u8Iterator = 0;
						Stepper_u8Iterator < STEPPER_u8PinNum;
						Stepper_u8Iterator++) {
					Stepper_voidReset();
					DIO_enumSetPinValue(Stepper_u8ArrPin[Stepper_u8Iterator],
					DIO_HIGH);
					_delay_ms(Copy_u8Speed);
				}
			}
		} else if (Copy_u8Direction == Stepper_u8CCW) {
			for (Stepper_u16Iterator2 = 0;
					Stepper_u16Iterator2
							< Stepper_u8DegreeToSteps(Copy_u16Degree);
					Stepper_u16Iterator2++) {
				for (Stepper_u8Iterator = 0;
						Stepper_u8Iterator < STEPPER_u8PinNum;
						Stepper_u8Iterator++) {
					Stepper_voidReset();
					DIO_enumSetPinValue(
							Stepper_u8ArrPin[3 - Stepper_u8Iterator],
							DIO_HIGH);
					_delay_ms(Copy_u8Speed);
				}
			}
		}
	}

	else if (Copy_u8Mode == Stepper_u8HalfStep) {
		for (Stepper_u16Iterator2 = 0;
				Stepper_u16Iterator2
						< Stepper_u8DegreeToSteps(Copy_u16Degree); Stepper_u16Iterator2++) {
			Stepper_voidHalf(Copy_u8Speed , Copy_u8Direction);
		}

	}
}

static void Stepper_voidReset(void) {
	DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_LOW);
	DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_LOW);
}

static void Stepper_voidHalf(u8 Copy_u8Speed, u8 Copy_u8Direction) {
	if (Copy_u8Direction == Stepper_u8CW) {
		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);
	}

	else if(Copy_u8Direction == Stepper_u8CCW){
		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_YELLOW_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_PINK_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);

		Stepper_voidReset();
		DIO_enumSetPinValue(STEPPER_u8_BLUE_COIL, DIO_HIGH);
		DIO_enumSetPinValue(STEPPER_u8_ORANGE_COIL, DIO_HIGH);
		_delay_ms(Copy_u8Speed);



	}
}
