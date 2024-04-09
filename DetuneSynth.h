#ifndef _DetuneSynth_H_
#define _DetuneSynth_H_
#include <iostream>
#include "oscillator.h"
#include "saw.h"
#include "Synth.h"

class DetuneSynth : public Synth{
  public:
    DetuneSynth(double sampleRate);
    ~DetuneSynth();

    void calculate();
    void changeParameter(double value);
    double getSample();

  protected:
    double sampleRate;
    double detAmount;
    Oscillator* osc;
    Oscillator* detOsc;

};

#endif
