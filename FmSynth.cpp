#include "FmSynth.h"

FmSynth::FmSynth(double sampleRate) : Synth(sampleRate){
  this -> sampleRate = sampleRate;
  carrier = new Sine(sampleRate);
  detOsc = new Sine(sampleRate);
}

FmSynth::~FmSynth(){
  delete carrier;
  delete detOsc;
}

void FmSynth::calculate(){
  carrier-> setFreq(freq);
  detOsc->setFreq(freq + detAmount);
  osc->tick();
  detOsc->tick();
}

void FmSynth::setDetuneAmount(double detAmount){
  this -> detAmount = detAmount;
}

double FmSynth::getSample(){
  return osc->getSample() + detOsc->getSample();
}
