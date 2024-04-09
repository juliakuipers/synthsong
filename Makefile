CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++20
LDFLAGS= -ljack
SOURCE=saw.o main.o oscillator.o square.o sine.o RmSynth.o DetuneSynth.o melodyGen.o Synth.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
