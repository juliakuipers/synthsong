#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "Synth.h"

class FmSynth : public Synth{
  public:
    FmSynth(double sampleRate);
    ~FmSynth();

    void calculate();
    void setModulatorAmount(double modAmount);
    void setModulatorRatio(double ratio);
    double getSample();

  protected:
    double sampleRate;
    double ratio;
    double modAmount;
    Oscillator* modulator;
    Oscillator* carrier;

};

#endif
