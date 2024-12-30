all: bin/nevpk bin/raw2bmp

bin/nevpk: build/nevpk.o build/compat.o build/log.o build/vpk.o
	g++ -o $@ $^

bin/raw2bmp: build/raw2bmp.o build/rawbmp.o build/raw2dcs.o build/compat.o build/dcs_encode.o build/dcs_decode.o build/dcs_address.o build/dcs_common.o build/rs.o
	g++ -o $@ $^

build/nevpk.o: tools/nevpk/main.cpp tools/nevpk/constants.h src/compat.h src/log.h src/vpk.h
	g++ -o $@ -c $<

build/raw2bmp.o: tools/raw2bmp/main.cpp tools/raw2bmp/constants.h src/compat.h src/rawbmp.h
	g++ -o $@ -c $<

build/compat.o: src/compat.cpp src/compat.h
	g++ -o $@ -c $<

build/log.o: src/log.cpp src/log.h src/compat.h
	g++ -o $@ -c $<

build/vpk.o: src/vpk.cpp src/vpk.h src/log.h
	g++ -o $@ -c $<

build/rawbmp.o: src/rawbmp.cpp src/rawbmp.h src/compat.h src/raw2dcs.h src/dcs_common.h src/dcs_encode.h src/dcs_decode.h
	g++ -o $@ -c $<

build/raw2dcs.o: src/raw2dcs.cpp src/raw2dcs.h src/dcs_common.h src/rs.h
	g++ -o $@ -c $<

build/dcs_encode.o: src/dcs_encode.cpp src/dcs_encode.h src/dcs_common.h src/dcs_address.h
	g++ -o $@ -c $<

build/dcs_decode.o: src/dcs_decode.cpp src/dcs_decode.h src/dcs_common.h
	g++ -o $@ -c $<

build/dcs_address.o: src/dcs_address.cpp src/dcs_address.h src/dcs_common.h
	g++ -o $@ -c $<

build/dcs_common.o: src/dcs_common.cpp src/dcs_common.h
	g++ -o $@ -c $<

build/rs.o: src/rs.cpp src/rs.h
	g++ -o $@ -c $<

clean:
	rm -f build/*.o bin/nevpk bin/raw2bmp
