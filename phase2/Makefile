all: hogwarts ainur

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
CXXTHREADFLAGS = -std=gnu++20 -g -fsanitize=thread,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build

hogwarts: $(BUILDDIR)/main
	@echo "\033[1;34mTestcase: hogwarts\033[0m"
	@$(BUILDDIR)/main hogwarts 1> $(BUILDDIR)/output.txt 2> /dev/null
	diff -Bw hogwarts/expected.txt $(BUILDDIR)/output.txt
	@rm $(BUILDDIR)/output.txt

hogwartsThread: $(BUILDDIR)/mainThread
	@echo "\033[1;34mTestcase: hogwartsThread\033[0m"
	@$(BUILDDIR)/mainThread hogwarts 1> $(BUILDDIR)/output.txt 2> /dev/null
	diff -Bw hogwarts/expected.txt $(BUILDDIR)/output.txt
	@rm $(BUILDDIR)/output.txt

ainur: $(BUILDDIR)/main
	@echo "\033[1;34mTestcase: ainur\033[0m"
	@$(BUILDDIR)/main ainur 1> $(BUILDDIR)/output.txt 2> /dev/null
	diff -Bw ainur/expected.txt $(BUILDDIR)/output.txt
	@rm $(BUILDDIR)/output.txt

ainurThread: $(BUILDDIR)/mainThread
	@echo "\033[1;34mTestcase: ainurThread\033[0m"
	@$(BUILDDIR)/mainThread ainur 1> $(BUILDDIR)/output.txt 2> /dev/null
	diff -Bw ainur/expected.txt $(BUILDDIR)/output.txt
	@rm $(BUILDDIR)/output.txt

$(BUILDDIR)/main: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/mainThread: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXTHREADFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all hogwarts hogwartsThread ainur ainurThread $(BUILDDIR)/main $(BUILDDIR)/mainThread clean
