all: hogwarts ainur

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = ~/build

hogwarts: $(BUILDDIR)/main
	@echo Testcase: hogwarts
	@$(BUILDDIR)/main hogwarts > $(BUILDDIR)/output.txt
	diff -Bw hogwarts/expected.txt $(BUILDDIR)/output.txt
	@rm  $(BUILDDIR)/main $(BUILDDIR)/output.txt

ainur: $(BUILDDIR)/main
	@echo Testcase: ainur
	@$(BUILDDIR)/main ainur > $(BUILDDIR)/output.txt
	diff -Bw ainur/expected.txt $(BUILDDIR)/output.txt
	@rm -rf $(BUILDDIR)/main $(BUILDDIR)/output.txt

$(BUILDDIR)/main: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all hogwarts ainur $(BUILDDIR)/main clean

