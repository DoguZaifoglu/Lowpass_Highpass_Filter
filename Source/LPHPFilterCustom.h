#pragma once
#include "JuceHeader.h"


// Defining the buttons/options on the interface.
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

