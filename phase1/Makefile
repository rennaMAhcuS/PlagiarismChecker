CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g -fsanitize=address,undefined $(CXXWARNINGS)
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build
PHASE1DIR = $(BUILDDIR)/phase1

all: main chrono score

# ============================================================

$(PHASE1DIR)/main: main.cpp tokenizer.cpp
	@mkdir -p $(PHASE1DIR)
	@echo "\033[1;33mCompiling main:\033[0m"
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

main: $(PHASE1DIR)/main
	@echo "\033[1;34mRunning main:\033[0m"
	@$(PHASE1DIR)/main 2> /dev/null
	@echo "\033[1m"'============================================================'"\033[0m"

# ============================================================

$(PHASE1DIR)/chrono: chrono.cpp tokenizer.cpp
	@mkdir -p $(PHASE1DIR)
	@echo "\033[1;33mCompiling chrono:\033[0m"
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

chrono: $(PHASE1DIR)/chrono
	@echo "\033[1;34mRunning chrono:\033[0m"
	@$(PHASE1DIR)/chrono 2> /dev/null
	@echo "\033[1m"'============================================================'"\033[0m"

# ============================================================

$(PHASE1DIR)/score: score.cpp tokenizer.cpp
	@mkdir -p $(PHASE1DIR)
	@echo "\033[1;33mCompiling score:\033[0m"
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

score: $(PHASE1DIR)/score
	@echo "\033[1;34mRunning score:\033[0m"
	@$(PHASE1DIR)/score 2> /dev/null
	@echo "\033[1m"'============================================================'"\033[0m"

# ============================================================

clean:
	rm -rf $(PHASE1DIR)

.PHONY: all main chrono score clean
