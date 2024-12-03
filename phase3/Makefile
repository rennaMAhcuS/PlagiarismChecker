all: main

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build
PHASE3DIR = $(BUILDDIR)/phase3

# The test and the checker parameters
test ?= one
ifneq ($(filter-out undefined,$(origin checker)),)
CPPFLAGS = -DCHECKER_NUMBER=$(checker)
endif

main: $(PHASE3DIR)/main
	@$(PHASE3DIR)/main 2> /dev/null
	@rm -rf $(PHASE3DIR)/main

$(PHASE3DIR)/main: main.cpp tokenizer.cpp
	@mkdir -p $(PHASE3DIR)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(PHASE3DIR)

.PHONY: all main $(PHASE3DIR)/main clean
