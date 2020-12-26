#include "VCO.h"
#define CPU_F 16000000
#include <util/delay.h>
#define STEP_D 200

// setup oscillator. clock speed is 16000000 hz (16Mhz)
VCO osc(16000000);


int main(){
	osc.init();

	while(true)
	{
		osc.setFrequency(440);
		_delay_ms(STEP_D);
		osc.setFrequency(466);
		_delay_ms(STEP_D);
		osc.setFrequency(494);
		_delay_ms(STEP_D);
		osc.setFrequency(523);
		_delay_ms(STEP_D);
		osc.setFrequency(554);
		_delay_ms(STEP_D);
		osc.setFrequency(587);
		_delay_ms(STEP_D);
		osc.setFrequency(622);
		_delay_ms(STEP_D);
		osc.setFrequency(659);
		_delay_ms(STEP_D);
		osc.setFrequency(698);
		_delay_ms(STEP_D);		
		osc.setFrequency(740);
		_delay_ms(STEP_D);		
		osc.setFrequency(784);
		_delay_ms(STEP_D);
		osc.setFrequency(831);
		_delay_ms(STEP_D);
		osc.setFrequency(880);
		_delay_ms(STEP_D);
		
	}
}