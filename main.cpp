#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#include "node.h"
#include "header.h"

using namespace std;

map<std::string, Stack> stacks;

void commands(const string& query){

    stringstream ss(query);
    string comm;
    ss >> comm;


    //StackBro
    if (comm == "Spush"){
        string stackName;
        string item;
        ss >> stackName >> item;
        stacks[stackName].push(item);
    }
    else if (comm == "Spop"){
        string stackName;
        ss >> stackName;
        stacks[stackName].pop();
    }
    else if (comm == "Sread"){
        string stackName;
        ss >> stackName;
        stacks[stackName].display();
    }
}

int main(int argc, char* argv[]){

    string query;
    cout << "Введите команды (или 'exit' для выхода):" << endl;
    while (true) {
        cout << "> ";
        getline(cin, query);
        if (query == "exit") {
            break; // Выход из цикла
        }
        commands(query);
    }

}