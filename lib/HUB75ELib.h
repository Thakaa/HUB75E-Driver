/*
 * HUB75ELib.h
 *
 *  Created on: May 28, 2020
 *      Author: raeeskattali
 */


#define HORIZONTAL_PIXELS			512
#define VERTICAL_PIXELS				64
#define PIXELS_COUNT				(HORIZONTAL_PIXELS * VERTICAL_PIXELS)
#define PIXELS_COUNT_IN_BYTES 		(PIXELS_COUNT/8)
#define HORIZONTAL_PIXELS_IN_BYTES 	(HORIZONTAL_PIXELS/8)

typedef enum {
	Red,
	Green,
	Blue,
	Yellow, //RG
	Pink, //RB
	Cyan, //GB
	White, //RGB
	Black //All off
}HUB75EDisplayColor;

typedef enum {
	BrightnessLevel1,
	BrightnessLevel2,
	BrightnessLevel3,
	BrightnessLevel4,
	BrightnessLevel5
}HUB75EDisplayBrightnessLevel;

typedef enum {
	HUB75EAddressingModeABCDE,
	HUB75EAddressingModeAC
}HUB75EAddressingMode;

void HUB75E_Init (void);
void HUB75E_clearDisplayBuffer();
void HUB75E_setDisplayBuffer(unsigned char pixels[]);
void HUB75E_DisplayOFF();
void HUB75E_displayBufferPixels();
void HUB75E_setDisplayBrightness(HUB75EDisplayBrightnessLevel b);
void HUB75E_setDisplayColor(HUB75EDisplayColor c);
