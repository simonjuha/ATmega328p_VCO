#include "VCO.h"
#define CPU_F 16000000
#include <util/delay.h>
#define STEP_D 1000


// setup oscillator. clock speed is 16000000 hz (16Mhz)
VCO osc(16000000,0);


int main(){
	osc.init();
	Serial.begin(9600);

	while(1)
	{
		osc.setFrequency((float)osc.getCV());

	}
}


