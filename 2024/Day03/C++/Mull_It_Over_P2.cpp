//SLEEPS
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>

int calculateConditionalMultiplications(const std::string& fileContent) {
	std::regex instructionPattern(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");
	std::smatch match;
	std::string::const_iterator searchStart(fileContent.cbegin());

	bool isEnabled = true; 
	int totalSum = 0;

	while (std::regex_search(searchStart, fileContent.cend(), match, instructionPattern)) {
		std::string instruction = match[0];
		if (instruction == "do()")
			isEnabled = true;
		else if (instruction == "don't()")
			isEnabled = false;
		else if (match[1].matched && match[2].matched)
			if (isEnabled) {
				int x = std::stoi(match[1].str());
				int y = std::stoi(match[2].str());
				totalSum += x * y;
			}
		searchStart = match.suffix().first;
	}
	return (totalSum);
}

int main()
{
    std::ifstream fileInput("test.txt");
	std::stringstream buffer;
	buffer << fileInput.rdbuf();
	std::string fileContent = buffer.str();
	int result = calculateConditionalMultiplications(fileContent);
	std::cout << "Sum of enabled multiplications: " << result << std::endl;
	return (0);
}
