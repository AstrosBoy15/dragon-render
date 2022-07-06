#include "Reader.h"

std::vector<std::string> Reader::readFile(std::string filePath, int numLines) {
    std::string currentLine;
    std::ifstream file(filePath);
    std::vector<std::string> lines;

    if (numLines != -1) {
        lines.reserve(numLines);
    }

    if (file.is_open()) {
        while (getline(file, currentLine)) {
            lines.push_back(currentLine);
        }

        file.close();
    } else {
        std::cout << "Unable to open file " << filePath << "!" << std::endl;
    }

    return lines;
}