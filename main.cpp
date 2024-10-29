#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "header.h"

using namespace std;

void processQuery(const string& query, SinglyLinkedList& singlyList, DoublyLinkedList& doublyList, Stack& stack, Queue& queue, Array& array, HashTable& hash, CBTree& CBTree){
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

    // Stack
    else if (tokens[0] == "SPUSH") {
        if (tokens.size() == 2){
            string value = tokens[1];
            stack.push(value);
        }
        else {
            cout << "Error: SPUSH requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "SPOP"){
        stack.pop();
    }

    // Queue
    else if (tokens[0] == "QPUSH"){
        if (tokens.size() == 2){
            string value = tokens[1];
            stack.push(value);
        }
        else {
            cout << "Error: QPUSH requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "QPOP"){
        queue.pop();
    }

    // Array
    else if (tokens[0] == "MPUSH"){
        if (tokens.size() == 3){
            int index = stoi(tokens[1]);
            string value = tokens[2];
            array.add(index, value);
        }
        else {
            cout << "Error: MPUSH requires 2 arguments..." << endl;
        }
    }
    else if (tokens[0] == "MDEL"){
        if (tokens.size() == 2){
            int index = stoi(tokens[1]);
            array.remove(index);
        }
        else {
            cout << "Error: MDEL requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "MGET"){
        if (tokens.size() == 2){
            int index = stoi(tokens[1]);
            string value = array.get(index);
            cout << "Element at index" << index << ": " << value << endl;
        }
        else {
            cout << "Error: MGET requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "MADD") {
        if (tokens.size() == 2){
            string value = tokens[1];
            array.addToEnd(value);
        }
        else {
            cout << "Error: MADD requires 1 argument..." << endl;
        }
    }
    else if (tokens[0] == "MREPLACE"){
        if (tokens.size() == 3){
            int index = stoi(tokens[1]);
            string value = tokens[2];
            array.replace(index, value);
        }
        else {
            cout << "Error: MREPLACE requires 2 arguments..." << endl;
        }
    }

    // HashTable
    else if (tokens[0] == "HSET"){
        if (tokens.size() == 3){
            string key = tokens[1];
            string value = tokens[2];
            hash.insert(key, value);
        }
        else {
            cout << "Error: HSET command requires 2 arguments" << endl;
        }
    } else if (tokens[0] == "HGET") {
        if (tokens.size() == 2) {
            string key = tokens[1];
            hash.get(key);
        }
    } else if (tokens[0] == "HDEL") {
        if (tokens.size() == 2) {
            string key = tokens[1];
            hash.remove(key);
        } else {
            cout << "Error: HDEL command requires 1 argument" << endl;
        }
    } else if (tokens[0] == "HPRINT"){
        hash.print();
    }

    // CBTree
    else if (tokens[0] == "TINSERT"){
        if (tokens.size() == 2) {
            int digit = stoi(tokens[1]);
            CBTree.insert(digit);
        } else {
            cout << "Error: TINSERT command requires 1 argument" << endl;
        }
    } else if (tokens[0] == "TISCBT"){
        if (CBTree.is_CBT()) {
            cout << "The tree is complete binary tree" << endl;
        } else {
            cout << "The tree is not a complete binary tree" << endl;
        }
    } else if (tokens[0] == "TFIND") {
        if (tokens.size() == 2) {
            int value = stoi(tokens[1]);
            if (CBTree.get_value(value)) {
                cout << "Value" << value << "found in the tree" << endl;
            } else {
                cout << "Value" << value << "not found in the tree" << endl;
            }
        } else {
            cout << "Error: TFIND command requires 1 argument" << endl;
        }
    } else if (tokens[0] == "TDISPLAY"){
        CBTree.display();
    }

    else if (tokens[0] == "PRINT"){
        array.print();
        stack.print();
        queue.print();
        singlyList.print();
        doublyList.print();
        hash.print();
    } else {
        cout << "Unknown command: " << tokens[0] << endl;
    }
}

int main(int argc, char* argv[]) {
    string query;
    string filename;
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;
    Stack stack;
    Queue queue;
    Array array(10);
    HashTable hash;
    CBTree CBTree;

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
        else if (command[0] == 'L' && command[1] == 'D'){
            doublyList.loadFromFile(filename);
        }

        // Проверка команд для stack
        else if (command[0] == 'S'){
            stack.loadFromFile(filename);
        }

        // Проверка команд для queue
        else if (command[0] == 'Q'){
            queue.loadFromFile(filename);
        }

        // Проверка команд для array
        else if (command[0] == 'M'){
            array.loadFromFile(filename);
        }

        // ПРоеврка команд для hashtable
        else if (command[0] == 'H'){
            hash.loadFromFile(filename);
        }

        // Проверка команд для CBTree
        else if (command[0] == 'T') {
            CBTree.loadFromFile(filename);
        }
    }

    // Выполнение запроса
    if (!query.empty()){
        processQuery(query, singlyList, doublyList, stack, queue, array, hash, CBTree);
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
        else if (command[0] == 'L' && command[1] == 'D'){
            doublyList.saveToFile(filename);
        }

        // Проверка команд для stack
        else if (command[0] == 'S'){
            stack.saveToFile(filename);
        }

        // Проверка команд для queue
        else if (command[0] == 'Q'){
            queue.saveToFile(filename);
        }

        // Проверка команд для array
        else if (command[0] == 'M'){
            array.saveToFile(filename);
        }

        // Проверка команд для hashtable
        else if (command[0] == 'H'){
            hash.saveToFile(filename);
        }

        else if (command[0] == 'T') {
            CBTree.saveToFile(filename);
        }
    }
    return 0;
}