#ifndef VCO_H_
#define VCO_H_
#include <avr/io.h>

class VCO
{
public:
	VCO(unsigned long cpu_f);
	void setFrequency(float hz);
	void init();
private:
	float scaler_;
};

#endif /* OSC_TIMERS_H_ */

