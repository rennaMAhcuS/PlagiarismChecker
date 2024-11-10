#include <chrono>
#include <fstream>
#include <iostream>

// color codes for good printing
const std::string RESET = "\033[00m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[01m";

template <typename T>
void printTimeTaken(T duration) {
    std::cout << BOLD << CYAN << "Time taken: " << duration << RESET << std::endl;
}

template <typename T>
void printContainer(T& v, const std::string& color = GREEN, bool bold = false, std::string sep = " ") {
    for (auto& i : v) {
        std::cout << color << i << RESET << sep;
    }
    std::cout << "\n";
}

template <typename T>
void printContainerToFile(T& v, std::string filename) {
    std::ofstream fileStream(filename);
    if (!fileStream) {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
    for (auto& i : v) {
        fileStream << i << "\n";
    }
    fileStream << "\n";
    fileStream.close();
}
