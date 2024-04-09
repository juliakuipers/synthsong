#include "Synth.h"

Synth::Synth(double sampleRate){
  this -> sampleRate = sampleRate;
}

Synth::~Synth(){}

void Synth::mTof(double pitch){
    freq = 440 * pow(2 , (pitch-69)/12);
}

void Synth::tick(){
  calculate();
}

double Synth::nextSample(){
    return getSample();
}
