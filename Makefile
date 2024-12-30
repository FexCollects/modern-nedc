all: bin/nevpk bin/raw2bmp

bin/nevpk: build/nevpk.o build/shim.o build/compat.o
	g++ -o bin/nevpk build/nevpk.o build/shim.o build/compat.o

build/nevpk.o: tools/nevpk/nevpk.cpp tools/nevpk/constants.h src/compat.h src/shim.h
	g++ -o build/nevpk.o -c tools/nevpk/nevpk.cpp

bin/raw2bmp: build/raw2bmp.o build/shim.o build/compat.o
	g++ -o bin/raw2bmp build/raw2bmp.o build/shim.o build/compat.o

build/raw2bmp.o: tools/raw2bmp/raw2bmp.cpp tools/raw2bmp/constants.h src/compat.h src/shim.h
	g++ -o build/raw2bmp.o -c tools/raw2bmp/raw2bmp.cpp

build/shim.o: src/shim.cpp src/shim.h
	g++ -o build/shim.o -c src/shim.cpp

build/compat.o: src/compat.cpp src/compat.h
	g++ -o build/compat.o -c src/compat.cpp
