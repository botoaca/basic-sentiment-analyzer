CXX = g++
CXXFLAGS = -Wall

all: build build/output

build:
	mkdir build

build/output: build/SentimentAnalyzer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/SentimentAnalyzer.o: src/SentimentAnalyzer.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@