#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "RmSynth.h"
#include "DetuneSynth.h"
#include "Synth.h"
#include "melodyGen.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback () : AudioCallback() {

    }

    ~CustomCallback() {
      delete synth;
      synth = nullptr;
      delete melGen;
      melGen = nullptr;
    }

    void prepare (int sampleRate) override {
      this->sampleRate = sampleRate;
    }

    void prepareSynth(){
      std::cout << "Press r for RM synth...\nPress d for Detune synth" << std::endl;
      bool running = true;
      while (running) {
          switch (std::cin.get()) {
              case 'r':
                  synth = new RmSynth(sampleRate);
                  running = false;
                  break;
              case 'd':
                  synth = new DetuneSynth(sampleRate);
                  running = false;
                  break;
          }
      } // kies een synth
      melGen = new MelodyGen(sampleRate);
      synth->mTof(60);
    }

    void synthSettings(){
      std::cout << "Enter ratio/detune value" << std::endl;
      double value = 0.0;
      std::cin >> value;
      synth->changeParameter(value);
      //zet input van user om in value
    }

    void changeMelody(){
      melGen->generateMelody();
      //genereer een nieuwe melodie
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


          for (int sample = 0u; sample < numFrames; ++sample) {
            synth->mTof(melGen->tick());
            //set de gegenereerde melodie om in frequentie voor de synth
            synth->tick();
            //bereken de nieuwe synth sample
            for (int channel = 0u; channel < numOutputChannels; ++channel) {
                outputChannels[channel][sample] = synth->getSample(); //inputChannels[0][sample];
                //Stuur sample uit van synth
            }
        }
    }

private:
  float sampleRate = 44100;
  Synth* synth;
  MelodyGen* melGen;
  //maak synth en melodygen dynamisch aan
};




int main() {
    auto callback = CustomCallback{};
    callback.prepareSynth();
    auto jackModule = JackModule{callback};
    jackModule.init(1,2);

    std::cout << "Press q Enter to quit...\nPress m for new melody...\nPress s for synth settings" << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'm':
              callback.changeMelody();
              std::cout << "Melody has been changed" << std::endl;
              break;
            case 's':
            callback.synthSettings();
        } //keuze menu voor gebruiker
    }


    return 0;
}
