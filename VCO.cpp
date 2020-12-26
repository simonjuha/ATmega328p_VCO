#include "VCO.h"
#include <avr/io.h>

VCO::VCO(unsigned long cpu_f = 16000000){
	// calculate scaler used to set frequency
	scaler_ = (cpu_f/(2*64));
}

void VCO::setFrequency(float hz){
	float top = (( (float) scaler_ / hz ) - 1);
	OCR1A = (int) top;
}


// Timer setup
void VCO::init(){
	// PB1 as output pin (pin 15 or arduino pin 9)
	DDRB |= (1<<DDB1);
	TCCR1A |= (0<<COM1A1) | (1<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
	// prescaler of 64
	TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
	OCR1A=0xA1;
}