#include "saw.h"
#include "math.h"

Saw::Saw(double samplerate) : Oscillator(samplerate){
}



Saw::~Saw() {
}

void Saw::calculate() {
  sample = phase * 2.0 - 1.0;
  sample *= amp;
}
