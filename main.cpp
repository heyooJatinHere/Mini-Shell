#include <iostream>
#include <string>
#include <vector>
#include "Utility.h"
#include "CommandHandler.h"
#include "ProcessHandler.h"

using namespace std;

int main(){
    string input;

    while(true){
        cout<<">> ";
        getline(cin, input);

        if(input.empty()) continue;

        vector<string> tokens=tokenize(input);

        if(tokens.empty()) continue;

        if(isBuiltInCommand(tokens[0])){
            executeBuiltInCommand(tokens);
        }else{
            executeExternalCommand(tokens);
        }
    }
    return 0;
}