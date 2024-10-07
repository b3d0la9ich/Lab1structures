#include <iostream>

#include "node.h"

using namespace std;

struct Stack{
    Node* top;
    Stack(){
        top = nullptr;
    }
    void push(string value);
    void pop();
    void display();
};

struct Queue{
    Node* head;
    Node* tail;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    void push(string value);
    void pop();
    void display();
};

struct Array{
    Node* head;
    int size;
    int capacity; // макс вместимость массива

    Array() : head(nullptr), size(0), capacity(0) {}

    Array(int max) : head(nullptr), size(0), capacity(max) {}

    void add(int index, string value);
    void addToEnd(string value);
    string get(int index);
    void remove(int index);
    void replace(int index, string value);
    int length();
    void display();
};