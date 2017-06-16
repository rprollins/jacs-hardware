CXXFLAGS  := -O3 -ffp-contract=off -fopenmp
LIBS      := -lbenchmark -fopenmp
BUILD_DIR := build
BIN_DIR   := bin
EXAMPLES := $(patsubst src/%.cc,bin/%,$(wildcard src/*.cc))

.PHONY : all clean

all : $(EXAMPLES)

bin/% : build/%.o | bin
	$(CXX) $< -o $@ $(LDFLAGS) $(LIBS)

build/%.o : src/%.cc | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

build :
	mkdir -p $(BUILD_DIR)

bin :
	mkdir -p $(BIN_DIR)

clean :
	rm bin/*
