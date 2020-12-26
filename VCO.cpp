#include "VCO.h"
#include <avr/io.h>

VCO::VCO(unsigned long cpu_f, unsigned int CVpin){
	// calculate scaler used to set frequency
	scaler_ = (cpu_f/(2*64));
	
	if ((CVpin < 8) && (CVpin >= 0))
	{
		CVpin_ = CVpin;
	}
	else
	{
		CVpin_ = 0;
	}
	
}

void VCO::setFrequency(float hz){
	float top = ((scaler_ / hz ) - 1);
	OCR1A = (int) top;
}


// Timer setup
void VCO::init(){
	// PB1 as output pin (pin 15 or arduino pin 9)
	DDRB |= (1<<DDB1);
	TCCR1A |= (0<<COM1A1) | (1<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
	// prescaler of 64
	TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
	
	
	// ADC settings
	DIDR0=(0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
	// set channel (default 0)
	ADMUX |= (CVpin_);
	ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
	ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
	

}

unsigned int VCO::getCV(){
		// begin digital to analog conversion
		ADCSRA|=(1<<ADSC);
		// wait for conversion to complete
		while ((ADCSRA & (1<<ADIF))==0);
		ADCSRA|=(1<<ADIF);
		lastCV_ = ADC;
		return lastCV_;
}