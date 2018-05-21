/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    setSize (400, 300);
    
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setRange(-48.0, 0.0);
    gainSlider.setValue(-1.0);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void GainSliderAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void GainSliderAudioProcessorEditor::sliderValueChanged(Slider *slider) {
    
    // db = 20 * log(x)
    // x = 10^(db/20)
    // this algo allows for the human ear to percieve a linear change in volume
    processor.rawVolume = pow(10, gainSlider.getValue() / 20);
    
    
}
