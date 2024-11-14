all: main test score

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = ~/build

main: $(BUILDDIR)/main
	@echo main
	@$(BUILDDIR)/main 2>/dev/null
	@rm -rf $(BUILDDIR)

$(BUILDDIR)/main: main.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

test: $(BUILDDIR)/test
	@echo test
	@$(BUILDDIR)/test 2>/dev/null
	@rm -rf $(BUILDDIR)

$(BUILDDIR)/test: test.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

score: $(BUILDDIR)/score
	@echo score
	@$(BUILDDIR)/score 2>/dev/null
	@rm -rf $(BUILDDIR)

$(BUILDDIR)/score: score.cpp tokenizer.cpp
	@mkdir -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: main test score clean
