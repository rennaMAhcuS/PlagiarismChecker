CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build
GRADERDIR = $(BUILDDIR)/autograder

$(GRADERDIR)/phase2: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@rm -rf $(GRADERDIR)
	@mkdir -p $(GRADERDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) -DGRADERDIR=\"$(GRADERDIR)\" $^ -o $@


clean:
	@rm -rf $(GRADERDIR)/phase2

.PHONY: $(GRADERDIR)/phase2 clean
