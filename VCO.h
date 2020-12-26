#ifndef VCO_H_
#define VCO_H_
#include <avr/io.h>

class VCO
{
public:
	VCO(unsigned long cpu_f = 16000000,unsigned int CVpin = 0);
	void setFrequency(float hz);
	void init();
	unsigned int getCV();
private:
	float scaler_;
	unsigned int lastCV_;
	unsigned int CVpin_;
};

#endif /* OSC_TIMERS_H_ */

