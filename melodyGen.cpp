#include "melodyGen.h"

MelodyGen::MelodyGen(double samplerate) {
  //de synth kan niet dynamisch aangemaakt worden omdat ik het dan niet als refrence door kan geven.
 this ->samplerate = samplerate;
 generateMelody();
}

MelodyGen::~MelodyGen(){}

int MelodyGen::tick(){
 sampleCount += 1;
 if(sampleCount >= samplerate){
     sampleCount = 0;
     melody[index];
     index += 1;
     if(index>15){
       index = 0;
     }
   }
   return melody[index];
 }

  void MelodyGen::generateMelody(){
    melody.clear();
    for(int i = 0; i < 16; i++){
      melody.push_back(rand()% 12 + 60);
    }
  }
