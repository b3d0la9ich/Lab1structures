#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "header.h"

using namespace std;

void processQuery(const string& query, SinglyLinkedList& singlyList){
    vector<string> tokens;
    stringstream ss(query);
    string token;

    while (getline(ss, token, ' ')){
        tokens.push_back(token);
    }

    // SinglyLinkedList
    if (tokens[0] == "LSADDHEAD") {
        if (tokens.size() == 2){
            string value = tokens[1];
            singlyList.addToHead(value);
        }
        else {
            cout << "Error: LSADDHEAD requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "LSADDTAIL"){
        if (tokens.size() == 2) {
            string value = tokens[1];
            singlyList.addToTail(value);
        }
        else {
            cout << "Error: LSADDTAIL requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "LSDELHEAD") {
        singlyList.removeHead();
    }
    else if (tokens[0] == "LSDELTAIL") {
        singlyList.removeTail();
    }
    else if (tokens[0] == "LSDELVALUE") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            singlyList.removeByValue(value);
        }
        else {
            cout << "Error: LSDELVALUE requires 1 argument..." << endl;
        }
    }
}