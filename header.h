#pragma once
#include <iostream>
#include "node.h"

using namespace std;

struct SinglyLinkedList {
    Node* head;
    int size;

    SinglyLinkedList() : head(nullptr), size(0) {}

    void addToHead(string value);
    void addToTail(string value);
    void removeHead();
    void removeTail();
    void removeByValue(string value);
    Node* search(string value);
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};