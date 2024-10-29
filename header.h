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

struct HashTable {
    static const int tablesize = 10;
    HashNode* table[tablesize];

    HashTable();
    ~HashTable();

    int hashfunction(const string& key);
    
    void insert(const string& key, const string& value);
    void get(const string& key);
    void remove(const string& key);
    void print();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

struct CBTree {
    TreeNode* root;
    CBTree() : root(nullptr) {}

    void insert(int digit);
    bool is_CBT();
    bool get_value(int value);
    void find_index(int index);
    bool find_value(TreeNode* current, int value);
    void display();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void print_CBT(TreeNode* current, int level);
};