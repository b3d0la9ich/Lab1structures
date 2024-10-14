#pragma once
#include <iostream>
#include <fstream>
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

    void addToEnd(string _item){ // добавление узла в конец списка
        dlNode* newNode = new dlNode(_item);
        if (is_empty()){
            first = newNode;
            last = newNode;
            return;
        }
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    void addToHead(string _item){
        dlNode* newNode = new dlNode(_item);
        if (is_empty()){
            first = newNode;
            last = newNode;
            return;
        }
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }

    void delFromHead(){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        dlNode* newNode = first;
        first = newNode->next;
        if (first){
            first->prev = nullptr;
        }
        else{
            last = nullptr;
        }
        delete newNode;
    }

    void delFromEnd(){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        dlNode* newNode = last;
        last = newNode->prev;
        if (last){
            last->next = nullptr;
        }
        else{
            first = nullptr;
        }
        delete newNode;
    }

    void printList(){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        dlNode* newNode = first;
        while (newNode){
            cout << newNode->item << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }

    void delItem(string _item){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        if (first->item == _item){
            delFromHead();
            return;
        }
        if (last->item == _item){
            delFromEnd();
            return;
        }
        dlNode* newFirst = first;
        dlNode* newLast = first->next;
        while (newLast && newLast->item != _item){
            newLast = newLast->next;
            newFirst = newFirst->next;
        }
        if (!newLast){
            cout << "Element not on the list" << endl;
            return;
        }
        newFirst->next = newLast->next;
        newLast->prev = newFirst->prev;
        delete newLast;
    }

    void findItem(string _item){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        dlNode* newNode = first;
        int index = 0;
        while (newNode && newNode->item != _item){
            newNode = newNode->next;
            index++;
        }
        if(!newNode){
            cout << "Element not on the list" << endl;
            return;
        }
        cout << "Index of element: " << index << endl;
    }

    void findIndex(int index){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        dlNode* newNode = first;
        for (int i = 0; i < index && newNode; i++){
            newNode = newNode->next;
        }
        if (!newNode){
            cout << "Element not on the list" << endl;
            return;
        }
        string _item = newNode->item;
        delete newNode;
        cout << "Element by index: " << _item << endl;
    }

    void loadFromFile(const string& file){
        clear();
        ifstream load(file);
        if (!load){
            cout << "Cant open the file" << endl;
            return;
        }
        string str;
        while (getline(load, str)){
            addToEnd(str);
        }
        load.close();
    }

    void saveToFile(const string& file){
        ofstream save(file);
        if (!save){
            cout << "Cant open the file" << endl;
            return;
        }
        dlNode* newNode = first;
        while (newNode){
            save << newNode->item << endl;
            newNode = newNode->next;
        }
        save.close();
        const_cast<doubleList*>(this)->clear();
    }
};