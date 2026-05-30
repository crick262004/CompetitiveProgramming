#include <sstream>
vector<string> splitByWhitespace(const string &str)
{
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token)
    { // Reads words separated by whitespace
   tokens.push_back(token);
    }
    return tokens;
}