CXXFLAGS ?= -Wall -Wextra -std=c++11

all: test
test: test.cpp
test.cpp: sipp.h
