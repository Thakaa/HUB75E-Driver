/*
 * HUB75E_Hal.h
 *
 *  Created on: May 28, 2020
 *      Author: raeeskattali
 */

#ifndef HUB75E_HAL_H_
#define HUB75E_HAL_H_

typedef enum {
	PinRed1,
	PinGreen1,
	PinBlue1,
	PinRed2,
	PinGreen2,
	PinBlue2,
	PinADDRA,
	PinADDRB,
	PinADDRC,
	PinADDRD,
	PinADDRE,
	PinCLK,
	PinLATCH,
	PinOE

}HUB75EPin;

void HUB75E_GPIO_Init(void);
void HUB75E_DelayUs(int us);
void HUB75E_setPin(HUB75EPin p, int state);

#endif /* HUB75E_HAL_H_ */
