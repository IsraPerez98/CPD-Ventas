CXX=g++
CXXFLAGS=-Wall -g3 -std=c++17
LDFLAGS=-lm
OBJECTOS=main.o leeryescribir.o matrizdatos.o
MKDIR=mkdir -p
DEL=rm -fr

all: $(OBJECTOS)
	$(MKDIR) bin
	$(CXX) $(CXXFLAGS) -o bin/app $(OBJECTOS) $(LDFLAGS)

clean:
	$(DEL) *.o app bin/

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

leeryescribir.o: leeryescribir.h leeryescribir.cpp
	$(CXX) $(CXXFLAGS) -c leeryescribir.cpp

matrizdatos.o: matrizdatos.h matrizdatos.cpp
	$(CXX) $(CXXFLAGS) -c matrizdatos.cpp


.PHONY: all