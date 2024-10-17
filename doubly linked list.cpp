#include <iostream>
#include <string>
#include <fstream>

#include "node.h"
#include "header.h"

using namespace std;

void DoublyLinkedList::addToHead(string value) {
    DoublyNode* newNode = new DoublyNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::addToTail(string value){
    DoublyNode* newNode = new DoublyNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoublyLinkedList::removeFromHead(){
    if (head == nullptr){
        return;
    }
    DoublyNode* temp = head;
    head = head->next;
    if (head != nullptr){
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeFromTail(){
    if (tail == nullptr){
        return;
    }
    DoublyNode* temp = tail;
    tail = tail->prev;
    if (tail != nullptr){
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeByValue(string value){
    if (head == nullptr) {
        return;
    }
    DoublyNode* current = head;
    while (current->next != nullptr){
        if (current->data == value){
            if (current == head){
                removeFromHead();
            }
            else if (current == tail){
                removeFromTail();
            }
            else {
                current->prev = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            return;
        }
        current = current->next;
    }
}

DoublyNode* DoublyLinkedList::search(string value){
    DoublyNode* current = head;
    while (current != nullptr){
        if (current->data == value){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::print(){
    DoublyNode* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    DoublyNode* current = head;
    while (current != nullptr) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}

void DoublyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string value;
        while (file >> value) {
            addToTail(value);
        }
        file.close();
    } else {
        cout << "Unable to open file..." << endl;
    }
}