all: main

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = ~/build

# The test and the checker parameters
test ?= one
ifneq ($(filter-out undefined,$(origin checker)),)
CPPFLAGS = -DCHECKER_NUMBER=$(checker)
endif

main: $(BUILDDIR)/main
	@$(BUILDDIR)/main 2> /dev/null
	@rm -rf $(BUILDDIR)/main

$(BUILDDIR)/main: main.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all main $(BUILDDIR)/main clean
