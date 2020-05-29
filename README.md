# HUB75E-Driver
HUB75E Driver for STM32 Microcontrollers

```C
int main(void) {

	HUB75E_Init();
	HUB75E_setDisplayBuffer(myBitmap); //Each bit represent each pixels. 1 Byte contains 8 pixels 
	HUB75E_setDisplayBrightness(BrightnessLevel1);
	HUB75E_setDisplayColor(Blue);
	while(1) {
 	   HUB75E_displayBufferPixels();
        }
}

```
**Configurations**

HORIZONTAL_PIXELS - HUB75ELib.h (Default to 512).  
VERTICAL_PIXEL - HUB75ELib.h (Default to 64).


