all: $(patsubst %.cpp, %, $(wildcard *.cpp))

%: %.cpp Makefile
	g++  $< -lboost_graph -o $@
