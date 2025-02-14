#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H
#include <string>
#include <vector>
using namespace std;

bool isBuiltInCommand(const string& command);
void executeBuiltInCommand(const vector<string>& tokens);

#endif