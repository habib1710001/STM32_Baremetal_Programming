#include "RCFilter.h"



void RCFilter_Init(RCFilter *filt, float cutoffFreqHz,float sampleTimeS){

	float RC = 1.0f / (6.28316530718f * cutoffFreqHz);

	filt -> coeff[0] = sampleTimeS / (sampleTimeS + RC);
	filt -> coeff[1] = RC / (sampleTimeS + RC);
}
float RCFilter_Update(RCFilter *filt, float input){

	filt -> out[1] = filt->out[0]; //previous output
	filt -> out[0] = filt-> coeff[0]*input + filt-> coeff[1]* filt->out[1];

	return (filt->out[0]);
}
