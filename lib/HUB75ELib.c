/*
 * HUB75ELib.c
 *
 *  Created on: May 28, 2020
 *      Author: raeeskattali
 */

#include "HUB75ELib.h"
#include "HUB75E_Hal.h"
#include <string.h>


unsigned char graphicsBuffer[PIXELS_COUNT_IN_BYTES] = {0};
HUB75EDisplayBrightnessLevel brightness;
HUB75EDisplayColor displayColor;
HUB75EAddressingMode addressingMode;

/*Initialize LED Matrix screen
 *
 */
void HUB75E_Init (void) {

	//Initialising GPIO lines used to connect to the display
	HUB75E_GPIO_Init();

	// Setting clock low
	HUB75E_setPin(PinCLK, 0);

	//Setting all RGB lines low
	HUB75E_setPin(PinRed1, 0);
	HUB75E_setPin(PinRed2, 0);
	HUB75E_setPin(PinGreen1, 0);
	HUB75E_setPin(PinGreen2, 0);
	HUB75E_setPin(PinBlue1, 0);
	HUB75E_setPin(PinBlue2, 0);

	//Setting Address lines to 0x00;
	HUB75E_setPin(PinADDRA, 0);
	HUB75E_setPin(PinADDRB, 0);
	HUB75E_setPin(PinADDRC, 0);
	HUB75E_setPin(PinADDRD, 0);
	HUB75E_setPin(PinADDRE, 0);

}

/*Clear the display buffer pixels
 *
 */
void HUB75E_clearDisplayBuffer() {
	memset(graphicsBuffer, 0,PIXELS_COUNT_IN_BYTES);
}

/*Set the Display brightness
 *
 */
void HUB75E_setDisplayBrightness(HUB75EDisplayBrightnessLevel b) {
	brightness = b;
}

/*Set the Display color
 *
 */
void HUB75E_setDisplayColor(HUB75EDisplayColor c) {
	displayColor = c;
}

/*Load the display buffer graphic pixels. Whatever loaded will be displayed by the HUB75E_displayBufferPixels()
 *
 */
void HUB75E_setDisplayBuffer(unsigned char pixels[]) {

	HUB75E_DisplayOFF();
	//memset(graphicsBuffer, 0XAE,PIXELS_COUNT);
	memcpy(graphicsBuffer, pixels, PIXELS_COUNT_IN_BYTES);
}

/*To turn off all the LEDs
 *
 */
void HUB75E_DisplayOFF() {
	HUB75E_setPin(PinOE, 1); //Setting OE high for turning off all LEDs
}

/*Set the addressing mode
 *
 */
void HUB75E_setAddressingMode(HUB75EAddressingMode addrMode) {
	addressingMode = addrMode;
}

/*Keep this running in your thread loop to get the display up running
 *
 */
void HUB75E_displayBufferPixels() {

	int upper_pixel_pointer = 0;
	int lower_pixel_pointer = PIXELS_COUNT_IN_BYTES/2;

	for(int row = 0; row < VERTICAL_PIXELS/2;) {
		for(int column = 0; column < HORIZONTAL_PIXELS_IN_BYTES; column++) { //Shifting pixels for each row. HORIZONTAL_PIXELS_IN_BYTES x 8

			int pB1 = graphicsBuffer[upper_pixel_pointer]; //upper half 8 pixels
			int pB2 = graphicsBuffer[lower_pixel_pointer]; //lower half 8 pixels

			for(int i = 7; i >= 0;) { //Shifting 8 pixels horizontally. MSb First

				int p1 = (pB1 >> i) & 1;
				int p2 = (pB2 >> i) & 1;

				switch(displayColor) {//Setting the right display color
					case Red:
						HUB75E_setPin(PinRed1, p1);
						HUB75E_setPin(PinRed2, p2);
						break;
					case Green:
						HUB75E_setPin(PinGreen1, p1);
						HUB75E_setPin(PinGreen2, p2);
						break;
					case Blue:
						HUB75E_setPin(PinBlue1, p1);
						HUB75E_setPin(PinBlue2, p2);
						break;
					case Yellow:
						HUB75E_setPin(PinRed1, p1);
						HUB75E_setPin(PinRed2, p2);
						HUB75E_setPin(PinGreen1, p1);
						HUB75E_setPin(PinGreen2, p2);
						break;
					case Pink:
						HUB75E_setPin(PinRed1, p1);
						HUB75E_setPin(PinRed2, p2);
						HUB75E_setPin(PinBlue1, p1);
						HUB75E_setPin(PinBlue2, p2);
						break;
					case Cyan:
						HUB75E_setPin(PinGreen1, p1);
						HUB75E_setPin(PinGreen2, p2);
						HUB75E_setPin(PinBlue1, p1);
						HUB75E_setPin(PinBlue2, p2);
						break;
					case White:
						HUB75E_setPin(PinRed1, p1);
						HUB75E_setPin(PinRed2, p2);
						HUB75E_setPin(PinGreen1, p1);
						HUB75E_setPin(PinGreen2, p2);
						HUB75E_setPin(PinBlue1, p1);
						HUB75E_setPin(PinBlue2, p2);
						break;
					case Black:
						//HUB75E_setPin(PinBlue1, (graphicsBuffer[upper_pixel_pointer] >> i) & 1);
						//HUB75E_setPin(PinBlue2, (graphicsBuffer[lower_pixel_pointer] >> i) & 1);
						break;
					default:
						HUB75E_setPin(PinRed1, p1);
						HUB75E_setPin(PinRed2, p2);
						break;
				}

				HUB75E_setPin(PinCLK, 1);
				i--; //Clock delay
				HUB75E_setPin(PinCLK, 0);
			}

			upper_pixel_pointer++;
			lower_pixel_pointer++;
		}

		switch (addressingMode)
		{
			case HUB75EAddressingModeABCDE:
				//Setting the row address (0 to 31)
				HUB75E_setPin(PinADDRA, (row & ( 1 << 0 )) >> 0);
				HUB75E_setPin(PinADDRB, (row & ( 1 << 1 )) >> 1);
				HUB75E_setPin(PinADDRC, (row & ( 1 << 2 )) >> 2);
				HUB75E_setPin(PinADDRD, (row & ( 1 << 3 )) >> 3);
				HUB75E_setPin(PinADDRE, (row & ( 1 << 4 )) >> 4);
				break;
			case HUB75EAddressingModeAC:
				if(row == 0) {
					HUB75E_setPin(PinADDRC, 1); //1 for Zeroth row 0 otherwise
				}
				else
				{
					HUB75E_setPin(PinADDRC, 0);
				}

				//Clocking
				HUB75E_setPin(PinADDRA, 1);
				HUB75E_DelayUs(1);
				HUB75E_setPin(PinADDRA, 0);
				break;
			default:
				break;
		}

		//Latch falling edge for data transfer to output drivers
		HUB75E_setPin(PinLATCH, 1);
		row++; //Clock delay
		HUB75E_setPin(PinLATCH, 0);

		HUB75E_setPin(PinOE, 0); //Setting OE high for turning on all LEDs
		switch(brightness) { //More the delay, more the brightness
			case BrightnessLevel1:
				HUB75E_DelayUs(1);
				break;
			case BrightnessLevel2:
				HUB75E_DelayUs(10);
				break;
			case BrightnessLevel3:
				HUB75E_DelayUs(50);
				break;
			case BrightnessLevel4:
				HUB75E_DelayUs(150);
				break;
			case BrightnessLevel5:
				HUB75E_DelayUs(250);
				break;
			default:
				HUB75E_DelayUs(50);
				break;
		}
		HUB75E_setPin(PinOE, 1); //Setting OE high for turning off all LEDs
	}
}
