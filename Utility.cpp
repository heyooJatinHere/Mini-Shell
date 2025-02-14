#include<sstream>
#include "Utility.h"
using namespace std;

vector<string> tokenize(const string& input){
    stringstream ss(input);
    vector<string> tokens;
    string token;
    while(ss>>token){
        tokens.push_back(token);
    }
    return tokens;
}