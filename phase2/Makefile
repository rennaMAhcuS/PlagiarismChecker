all: main

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = ~/build

main: $(BUILDDIR)/main
	@$(BUILDDIR)/main hogwarts > $(BUILDDIR)/output.txt
	diff -Bw hogwarts/expected.txt $(BUILDDIR)/output.txt
	@rm $(BUILDDIR)

$(BUILDDIR)/main: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: main clean
