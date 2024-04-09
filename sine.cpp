#include "sine.h"
#include "math.h"

Sine::Sine(double samplerate) : Oscillator(samplerate){
}

Sine::~Sine(){
}

void Sine::calculate(){
    // std::cout << "Sine - Calculate - sample " << sample << "\n";
    sample = sin(M_PI * 2 * phase) * amp;
}
