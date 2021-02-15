/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"

#include "../MCAL/01-DIO/DIO_interface.h"

#include "../HAL/06- Stepper/Stepper_interface.h"
#include <util/delay.h>



int main(void) {
	Stepper_voidInit();

while(1){
	Stepper_voidOn(Stepper_u8HalfStep , Stepper_u8CW , Stepper_u8MediumSpeed , 180);
	_delay_ms(1000);
	Stepper_voidOn(Stepper_u8FullStep , Stepper_u8CCW , Stepper_u8MediumSpeed , 180);
	_delay_ms(1000);
	Stepper_voidOff();
	_delay_ms(1000);
	Stepper_voidOn(Stepper_u8HalfStep , Stepper_u8CW , Stepper_u8MediumSpeed , 180);
	_delay_ms(1000);
	Stepper_voidOn(Stepper_u8FullStep , Stepper_u8CCW , Stepper_u8MediumSpeed , 180);

}

}
