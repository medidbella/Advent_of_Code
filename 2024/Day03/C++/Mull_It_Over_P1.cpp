//SLEEPS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

int mul(int a, int b) {
    return a * b;
}

int extractAndMultiply(const string& line) {
    regex mulRegex(R"(mul\((\d+),(\d+)\))");
    smatch match;
    int sum = 0;
    string::const_iterator searchStart(line.cbegin());
    while (regex_search(searchStart, line.cend(), match, mulRegex)) {
        int a = stoi(match[1]);
        int b = stoi(match[2]);
        sum += mul(a, b);
        searchStart = match.suffix().first;
    }
    return sum;
}

int main(void) {
    ifstream inputFile("test.txt");
    string line;
    int totalSum = 0;
    while (getline(inputFile, line)) {
        totalSum += extractAndMultiply(line);
    }
    cout << "Total sum: " << totalSum << endl;
    return 0;
}
