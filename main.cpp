#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "header.h"

using namespace std;

void processQuery(const string& query, SinglyLinkedList& singlyList, DoublyLinkedList& doublyList){
    vector<string> tokens;
    stringstream ss(query);
    string token;

    while (getline(ss, token, ' ')){
        tokens.push_back(token);
    }

    // Singly linked list
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

    // Doubly linked list
    else if (tokens[0] == "LDADDHEAD"){
        if (tokens.size() == 2){
            string value = tokens[1];
            doublyList.addToHead(value);
        }
        else {
            cout << "Error: LDADDHEAD requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "LDADDTAIL"){
        if (tokens.size() == 2){
            string value = tokens[1];
            doublyList.addToTail(value);
        }
        else {
            cout << "Error: LDADDTAIL requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "LDDELHEAD"){
        doublyList.removeFromHead();
    }
    else if (tokens[0] == "LDDELTAIL"){
        doublyList.removeFromTail();
    }
    else if (tokens[0] == "LDDVALUE"){
        if (tokens.size() == 2){
            string value = tokens[1];
            doublyList.removeByValue(value);
        }
        else {
            cout << "Error: LDDELVALUE requires 1 argument..." << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    string query;
    string filename;
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;

    // Чтение аргументов командной строки
    for (int i = 1; i < argc; i++){
        string arg = argv[i];
        if (arg == "--file" && i + 1 < argc){
            filename = argv[++i];
        }
        if (arg == "--query" && i + 1 < argc){
            query = argv[++i];
        }
    }

    if (!filename.empty() && !query.empty()){
        stringstream ss(query);
        string command;
        ss >> command;

        // Проверка команд для singly linked list
        if (command[0] == 'L' && command[1] == 'S'){
            singlyList.loadFromFile(filename);
        }

        // Проверка команд для doubly linked list
        if (command[0] == 'L' && command[1] == 'D'){
            doublyList.loadFromFile(filename);
        }
    }

    // Выполнение запроса
    if (!query.empty()){
        processQuery(query, singlyList, doublyList);
    }
    else {
        cout << "Error: query not specified..." << endl;
        return 1;
    }

    // Сохранение данных для структур
    if (!filename.empty() && !query.empty()){
        stringstream ss(query);
        string command;
        ss >> command;

        // Проверка команд для singly linked list
        if (command[0] == 'L' && command[1] == 'S') {
            singlyList.saveToFile(filename);
        }

        // Проверка команд для doubly linked list
        if (command[0] == 'L' && command[1] == 'D'){
            doublyList.saveToFile(filename);
        }
    }
    return 0;
}