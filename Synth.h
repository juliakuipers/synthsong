#ifndef _Synth_H_
#define _Synth_H_
#include <iostream>
#include "math.h"

class Synth{
  public:
    Synth(double samplerate);
    virtual ~Synth();

    void tick();
    double nextSample();
    void mTof(double pitch);
    virtual void calculate() = 0;
    virtual double getSample() = 0;
    virtual void changeParameter(double value) =0;

  protected:
      double sampleRate;
      double freq;
      double pitch;

};
#endif
