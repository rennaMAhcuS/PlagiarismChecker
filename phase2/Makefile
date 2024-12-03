CXX = clang++
CXXWARNINGS = -Wall -Wshadow -Wuninitialized -Wtype-limits -Wno-unused-variable
CXXFLAGS = -std=gnu++20 -g $(CXXWARNINGS)
CXXADDRESSFLAGS = $(CXXFLAGS) -fsanitize=address,undefined
CXXTHREADFLAGS = $(CXXFLAGS) -fsanitize=thread,undefined
INCLUDEFLAGS = -I/usr/lib/llvm-18/include
LDFLAGS = -lclang -L/usr/lib/llvm-18/lib -rpath /usr/lib/llvm-18/lib -fuse-ld=lld

# The build directory
BUILDDIR = $(HOME)/build
PHASE2DIR = $(BUILDDIR)/phase2

all: nosanitize address thread

# ============================================================

$(PHASE2DIR)/main-nosanitize: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@echo "\033[1;33mCompiling with no sanitize flags:\033[0m"
	@mkdir -p $(PHASE2DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

nosanitize: $(PHASE2DIR)/main-nosanitize
	@echo "\033[1;33mRunning main-nosanitize:\033[0m"

	@echo "\033[1;34mTestcase: hogwarts\033[0m"
	@$(PHASE2DIR)/main-nosanitize hogwarts 1> $(PHASE2DIR)/output.txt
	diff -Bw hogwarts/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt

	@echo "\033[1m"'========================================'"\033[0m"

	@echo "\033[1;34mTestcase: ainur\033[0m"
	@$(PHASE2DIR)/main-nosanitize ainur 1> $(PHASE2DIR)/output.txt
	diff -Bw ainur/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt
	@echo "\033[1m"'============================================================'"\033[0m"


# ============================================================

$(PHASE2DIR)/main-address: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@echo "\033[1;33mCompiling with address sanitize flags:\033[0m"
	@mkdir -p $(PHASE2DIR)
	$(CXX) $(CXXADDRESSFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

address: $(PHASE2DIR)/main-address
	@echo "\033[1;33mRunning main-address:\033[0m"

	@echo "\033[1;34mTestcase: hogwarts\033[0m"
	@$(PHASE2DIR)/main-address hogwarts 1> $(PHASE2DIR)/output.txt
	diff -Bw hogwarts/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt

	@echo "\033[1m"'========================================'"\033[0m"

	@echo "\033[1;34mTestcase: ainur\033[0m"
	@$(PHASE2DIR)/main-address ainur 1> $(PHASE2DIR)/output.txt
	diff -Bw ainur/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt
	@echo "\033[1m"'============================================================'"\033[0m"

# ============================================================

$(PHASE2DIR)/main-thread: main.cpp plagiarism_checker.cpp tokenizer.cpp
	@echo "\033[1;33mCompiling with thread sanitize flags:\033[0m"
	@mkdir -p $(PHASE2DIR)
	$(CXX) $(CXXTHREADFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) $^ -o $@

thread: $(PHASE2DIR)/main-thread
	@echo "\033[1;33mRunning main-thread:\033[0m"

	@echo "\033[1;34mTestcase: hogwarts\033[0m"
	@$(PHASE2DIR)/main-thread hogwarts 1> $(PHASE2DIR)/output.txt
	diff -Bw hogwarts/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt

	@echo "\033[1m"'========================================'"\033[0m"

	@echo "\033[1;34mTestcase: ainur\033[0m"
	@$(PHASE2DIR)/main-thread ainur 1> $(PHASE2DIR)/output.txt
	diff -Bw ainur/expected.txt $(PHASE2DIR)/output.txt || true
	@rm $(PHASE2DIR)/output.txt
	@echo "\033[1m"'============================================================'"\033[0m"

# ============================================================

clean:
	rm -rf $(PHASE2DIR)

.PHONY: all hogwarts hogwarts-thread ainur ainur-thread clean
