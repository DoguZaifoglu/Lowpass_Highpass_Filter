#pragma once
#include "JuceHeader.h"


// This defines the interface of the lowpass/highpass filter.
class LPHPFilterCustom
{
public:
	void setHighpass(bool highpass);
	void setCutoffFrequency(float cutoffFrequency);
	void setSamplingRate(float samplingRate);

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
	bool highpass;
	float cutoffFrequency;
	float samplingRate;
	std::vector<float> dnBuffer;
};
