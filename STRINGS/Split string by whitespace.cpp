// Split string by “ “ : Combine with the C++ Folder string manipulation file

#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitByWhitespace(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
        // Reads words separated by whitespace
        tokens.push_back(token);
    }
    return tokens;
}
