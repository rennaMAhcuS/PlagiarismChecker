CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build
GRADERDIR = $(BUILDDIR)/autograder

$(GRADERDIR)/phase1: main.cpp tokenizer.cpp
	@mkdir -p $(GRADERDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	@rm -rf $(GRADERDIR)/phase1

.PHONY: $(GRADERDIR)/phase1 clean
