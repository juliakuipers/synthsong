#include "RmSynth.h"

RmSynth::RmSynth(double sampleRate) : Synth(sampleRate){
  this -> sampleRate = sampleRate;
  modulator = new Sine(sampleRate);
  carrier = new Sine(sampleRate);
}

RmSynth::~RmSynth(){
  delete modulator;
  delete carrier;
}

void RmSynth::calculate(){
  modulator-> setFreq(freq * ratio);
  carrier->setFreq(freq);
  modulator->tick();
  carrier->tick();
}

void RmSynth::changeParameter(double value){
  this-> ratio = value;
}

double RmSynth::getSample(){
  return carrier->getSample()*modulator->getSample();
}
