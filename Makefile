# minimalist makefile
.SUFFIXES:
#
.SUFFIXES: .cpp .o .c .h
ifeq ($(DEBUG),1)
GENFLAGS = -fPIC  -ggdb  -march=native -Wall -Wextra -pedantic -Wshadow -fsanitize=undefined  -fno-omit-frame-pointer -fsanitize=address -Wno-unused
else
GENFLAGS =  -fPIC -O3  -march=native -Wall -Wextra -pedantic -Wshadow -Wno-unused
endif # debug
CFLAGS =  -std=c99 $(GENFLAGS)
CXXFLAGS = -std=c++11 -fpermissive $(GENFLAGS)

HEADERS=src/bpacking.h src/dict.h  src/scalar.h src/avxbpacking.h src/avxcodec.h  src/avxdict.h
EXECUTABLES=scalartest avxtest decodebenchmark

all: $(EXECUTABLES)

test: $(EXECUTABLES)
	@(./scalartest && ./avxtest && echo "\033[0;32mAll tests ok\033[0m" ) || (echo "\033[0;31mSome tests failed\033[0m")

scalartest : ./tests/scalartest.cpp  $(HEADERS)
	$(CXX) $(CXXFLAGS) -o scalartest ./tests/scalartest.cpp -Isrc

avxtest : ./tests/avxtest.cpp  $(HEADERS)
	$(CXX) $(CXXFLAGS) -o avxtest ./tests/avxtest.cpp -Isrc

decodebenchmark : ./benchmarks/decodebenchmark.cpp ./benchmarks/benchmark.h  $(HEADERS)
	$(CXX) $(CXXFLAGS) -o decodebenchmark ./benchmarks/decodebenchmark.cpp -Isrc -Ibenchmarks

clean:
	rm -f $(EXECUTABLES)
