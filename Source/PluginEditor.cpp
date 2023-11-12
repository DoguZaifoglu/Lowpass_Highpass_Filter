/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LPHPFilterCustomAudioProcessorEditor::LPHPFilterCustomAudioProcessorEditor (LPHPFilterCustomAudioProcessor& p, juce::AudioProcessorValueTreeState& vsts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(cutoffFrequencySlider);
    cutoffFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    cutoffFrequencyAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(vsts, "cutoff_frequency", cutoffFrequencySlider));
    
    addAndMakeVisible(cutoffFrequencyLabel);
    cutoffFrequencyLabel.setText("Cutoff Frequency", juce::dontSendNotification);

    addAndMakeVisible(highpassButton);
    highpassAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment(vsts, "highpass", highpassButton));

    addAndMakeVisible(highpassButtonLabel);
    highpassButtonLabel.setText("Highpass", juce::dontSendNotification);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
}

LPHPFilterCustomAudioProcessorEditor::~LPHPFilterCustomAudioProcessorEditor()
{
}

//==============================================================================
void LPHPFilterCustomAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::transparentBlack);
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::transparentBlack);
    g.setFont (15.0f);
    
}

void LPHPFilterCustomAudioProcessorEditor::resized()
{
    cutoffFrequencySlider.setBounds({ 15, 35, 100, 300 }); //initial x, initial y, width, height
    cutoffFrequencyLabel.setBounds({ cutoffFrequencySlider.getX() + 20, cutoffFrequencySlider.getY() - 40, 200, 50 }); //initial x, initial y, width, height
    cutoffFrequencyLabel.setFont(18.0f);

    highpassButton.setBounds({ cutoffFrequencySlider.getX() + 30,
                               cutoffFrequencySlider.getY() + cutoffFrequencySlider.getHeight() + 15, 30, 50 });
    highpassButtonLabel.setBounds({ cutoffFrequencySlider.getX() + highpassButton.getWidth()+28,
                                    highpassButton.getY(),
                                    cutoffFrequencySlider.getWidth() - highpassButton.getWidth(),
                                    highpassButton.getHeight() });
    highpassButtonLabel.setFont(18.0f);


}
