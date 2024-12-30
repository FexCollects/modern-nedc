all: bin/nevpk bin/raw2bmp

bin/nevpk: build/nevpk.o build/compat.o build/log.o build/vpk.o
	g++ -o bin/nevpk build/nevpk.o build/compat.o build/log.o build/vpk.o

build/nevpk.o: tools/nevpk/main.cpp tools/nevpk/constants.h src/compat.h src/log.h src/vpk.h
	g++ -o build/nevpk.o -c tools/nevpk/main.cpp

bin/raw2bmp: build/raw2bmp.o build/shim.o build/compat.o
	g++ -o bin/raw2bmp build/raw2bmp.o build/shim.o build/compat.o

build/raw2bmp.o: tools/raw2bmp/main.cpp tools/raw2bmp/constants.h src/compat.h src/shim.h
	g++ -o build/raw2bmp.o -c tools/raw2bmp/main.cpp

build/shim.o: src/shim.cpp src/shim.h
	g++ -o build/shim.o -c src/shim.cpp

build/compat.o: src/compat.cpp src/compat.h
	g++ -o build/compat.o -c src/compat.cpp

build/log.o: src/log.cpp src/log.h src/compat.h
	g++ -o build/log.o -c src/log.cpp

build/vpk.o: src/vpk.cpp src/vpk.h src/log.h
	g++ -o build/vpk.o -c src/vpk.cpp

clean:
	rm -f build/*.o bin/nevpk bin/raw2bmp
