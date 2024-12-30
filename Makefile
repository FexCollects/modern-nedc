bin/raw2bmp: build/raw2bmp.o build/shim.o
	g++ -o bin/raw2bmp build/raw2bmp.o build/shim.o

build/raw2bmp.o: tools/raw2bmp/raw2bmp.cpp src/compat.h src/shim.h
	g++ -o build/raw2bmp.o -c tools/raw2bmp/raw2bmp.cpp

build/shim.o: src/shim.cpp src/shim.h
	g++ -o build/shim.o -c src/shim.cpp
