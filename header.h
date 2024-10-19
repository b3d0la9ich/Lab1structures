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

struct Queue {
    Node* front;
    Node* end;
    int size;

    Queue() : front(nullptr), end(nullptr), size(0) {}

    void push(string value);
    void pop();
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

struct Array {
    string* data;
    int size;
    int maxCapacity;

    Array(int max);
    ~Array();

    void add(int index, string value);
    void addToEnd(string value);
    string get(int index);
    void remove(int index);
    void replace(int index, string value);
    int length();
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};