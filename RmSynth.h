#ifndef _RmSynth_H_
#define _RmSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "Synth.h"

class RmSynth : public Synth{
  public:
    RmSynth(double sampleRate);
    ~RmSynth();

    void calculate();
    void changeParameter(double value);
    double getSample();

  protected:
    double sampleRate;
    double ratio;
    double modAmount;
    Oscillator* modulator;
    Oscillator* carrier;

};

#endif
