# HUB75E-Driver
HUB75E Driver for STM32 Microcontrollers

```C
int main(void) {

	HUB75E_Init();
	HUB75E_setDisplayBuffer(myBitmap);
	HUB75E_setDisplayBrightness(BrightnessLevel1);
	HUB75E_setDisplayColor(Blue);
	while(1) {
		HUB75E_displayBufferPixels();
  }
}
