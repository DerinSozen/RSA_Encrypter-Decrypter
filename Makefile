CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec

bin/exec: ./src/main.cc ./src/utilities.cc ./src/key_handling.cc ./includes/key_handling.hpp ./includes/utilities.hpp
	$(CXX) $(CXXFLAGS) ./src/main.cc ./src/utilities.cc ./src/key_handling.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* 
