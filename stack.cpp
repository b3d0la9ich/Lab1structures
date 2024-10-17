#include <iostream>
#include <fstream>

#include "node.h"
#include "header.h"

using namespace std;

void Stack::push(string value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}

void Stack::pop(){
    if (top == nullptr){
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    size--;
}

void Stack::print(){
    Node* current = top;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Cannot open file for writing: " << filename << endl;
        return;
    }
    Node* temp = top;
    while (temp) {
        outFile << temp->data << endl;
        temp = temp->next;
    }
    outFile.close();
}

void Stack::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Cannot open file for reading: " << filename << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        push(line);
    }
    inFile.close();
}