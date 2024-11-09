CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# Default value for CHECKER_NUMBER
CHECKER_NUMBER ?= 0  # To give CHECKER_NUMBER through CLI, run `make <type> CHECKER_NUMBER=<number>`
CPPFLAGS = -DCHECKER_NUMBER=$(CHECKER_NUMBER)

main: main.cpp tokenizer.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@
	./main
	rm -rf main.dSYM main

test: test.cpp tokenizer.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@
	./test
	rm -rf test.dSYM test

score: score.cpp tokenizer.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@
	./score
	rm -rf score.dSYM score

clean:
	rm main test score
	rm -rf *.dSYM

.PHONY: main test score clean
