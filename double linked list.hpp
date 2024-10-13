#pragma once
#include <iostream>
#include <string>

using namespace std;

struct dlNode {
    string item;
    dlNode* next;
    dlNode* prev;

    dlNode(string _item) : item(_item), next(nullptr), prev(nullptr) {}
};

struct doubleList {
    dlNode* first;
    dlNode* last;
    doubleList() : first(nullptr), last(nullptr) {}

    ~doubleList() {
        clear();
    }

    void clear() {
        while (first){
            //delFromHead();
        }
    }

    bool is_empty(){
        return first == nullptr;
    }
};