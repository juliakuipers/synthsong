#include "DetuneSynth.h"

DetuneSynth::DetuneSynth(double sampleRate) : Synth(sampleRate){
  this -> sampleRate = sampleRate;
  osc = new Saw(sampleRate);
  detOsc = new Saw(sampleRate);
}

DetuneSynth::~DetuneSynth(){
  delete osc;
  delete detOsc;
}

void DetuneSynth::calculate(){
  detOsc-> setFreq(freq + detAmount);
  osc->setFreq(freq);
  detOsc->tick();
  osc->tick();
}

void DetuneSynth::changeParameter(double value){
  this -> detAmount = value;
}

double DetuneSynth::getSample(){
  return osc->getSample() + detOsc->getSample();
}
