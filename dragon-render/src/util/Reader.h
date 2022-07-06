#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Reader {
public:
	static std::vector<std::string> readFile(std::string filePath, int numLines = -1);
};