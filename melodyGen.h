#ifndef _melGen_H_
#define _melGen_H_
#include <iostream>
#include "Synth.h"
#include <stdlib.h>
#include <vector>

class MelodyGen{
    public:
        MelodyGen(double samplerate);
        ~MelodyGen();

        int tick();
        void generateMelody();


    private:
        std::vector<int> melody;
        int index = 0;
        int sampleCount = 0;
        double samplerate;
};

#endif /* end of include guard:  */
