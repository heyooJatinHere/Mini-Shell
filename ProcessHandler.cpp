#include "ProcessHandler.h"
#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
#include<cstdlib>

void executeExternalCommand(const vector<string>& tokens){
    if(tokens.empty()) return;

    string command=tokens[0];
    for(size_t i=1;i<tokens.size();i++){
        command+=" "+tokens[i];
    }

    int result=system(command.c_str());

    if(result==-1){
        perror("Command execution failed");
    }
}
