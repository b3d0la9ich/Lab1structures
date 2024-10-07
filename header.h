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