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

struct DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;
    int size;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addToHead(string value);
    void addToTail(string value);
    void removeFromHead();
    void removeFromTail();
    void removeByValue(string value);
    DoublyNode* search(string value);
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

struct Stack {
    Node* top;
    int size;

    Stack() : top(nullptr), size(0) {}

    void push(string value);
    void pop();
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};