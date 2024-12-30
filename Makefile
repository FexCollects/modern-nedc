all: bin/nevpk bin/raw2bmp

bin/nevpk: build/nevpk.o build/compat.o build/log.o build/vpk.o
	g++ -o $@ $^

bin/raw2bmp: build/raw2bmp.o build/shim.o build/compat.o
	g++ -o $@ $^

build/nevpk.o: tools/nevpk/main.cpp tools/nevpk/constants.h src/compat.h src/log.h src/vpk.h
	g++ -o $@ -c $<

build/raw2bmp.o: tools/raw2bmp/main.cpp tools/raw2bmp/constants.h src/compat.h src/shim.h
	g++ -o $@ -c $<

build/shim.o: src/shim.cpp src/shim.h
	g++ -o $@ -c $<

build/compat.o: src/compat.cpp src/compat.h
	g++ -o $@ -c $<

build/log.o: src/log.cpp src/log.h src/compat.h
	g++ -o $@ -c $<

build/vpk.o: src/vpk.cpp src/vpk.h src/log.h
	g++ -o $@ -c $<

clean:
	rm -f build/*.o bin/nevpk bin/raw2bmp
