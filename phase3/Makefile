all: main

CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# `make check=<number> test=<folder_name>`
test ?= one
ifneq ($(filter-out undefined,$(origin checker)),)
CPPFLAGS = -DCHECKER_NUMBER=$(checker)
endif

main: main.cpp tokenizer.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@
	@./main $(test)
	@rm -rf main main.dSYM

clean:
	@rm -rf main main.dSYM > /dev/null

.PHONY: main clean
