#include "CommandHandler.h"
#include<iostream>
#include<unistd.h>
#include<limits.h>
#include <string>
using namespace std;

bool isBuiltInCommand(const string& command){
    return (command=="cd" || command=="pwd" || command=="exit" || command=="type" || command=="echo");
}

void executeBuiltInCommand(const vector<string>& tokens){
    if(tokens.empty()){
        return;
    }

    string cmd=tokens[0];

    if(cmd=="cd"){
        if(tokens.size()<2){
            cerr<<"cd: missing argument\n";
            return;
        }
        if(chdir(tokens[1].c_str())!=0){
            perror("cd failed");
        }
    }else if(cmd=="pwd"){
        char cwd[PATH_MAX];
        if(getcwd(cwd, sizeof(cwd))!=nullptr){
            cout<<cwd<<endl;
        }else{
            perror("pwd failed");
        }
    }else if(cmd=="echo"){
        for(size_t i=1;i<tokens.size();i++){
            cout<<tokens[i]<<" ";
        }
        cout<<endl;
    }else if(cmd=="type"){
        if(tokens.size()<2){
            cerr<<"type: missing argument\n";
            return;
        }
        string subCmd=tokens[1];

        if(isBuiltInCommand(subCmd)){
            cout<<subCmd<<" is a built-in command\n";
        }else{
            cout<<subCmd<<" is an external command\n";
        }
    }else if(cmd=="exit"){
        exit(0);
    }
}