#include <iostream>
#include <string>
#include <fstream>

#include "node.h"
#include "header.h"

using namespace std;

void SinglyLinkedList::addToHead(string value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    size++;
}

void SinglyLinkedList::addToTail(string value){
    Node* new_node = new Node(value);
    if (head == nullptr){
        head = new_node;
    }
    else {
        Node* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = new_node;
    }
    size++;
}

void SinglyLinkedList::removeHead(){
    if (head == nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

void SinglyLinkedList::removeTail(){
    if (head == nullptr){
        return;
    }
    else{
        Node* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    size--;
}

void SinglyLinkedList::removeByValue(string value){
    if (head == nullptr){
        return;
    }
    if (head->data == value){
        removeHead();
        return;
    }
    Node* current = head;
    while (current->next != nullptr){
        if (current->next->data == value){
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

Node* SinglyLinkedList::search(string value){
    Node* current = head;
    while (current != nullptr){
        if (current->data == value){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void SinglyLinkedList::print(){
    Node* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void SinglyLinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        Node* current = head;
        while (current != nullptr) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    } else {
        cout << " Unable to open file " << filename << endl;
    }
}

void SinglyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string value;
        while (getline(file, value)) {
            addToTail(value); // Добавляем каждый элемент в хвост
        }
        file.close();
    } else {
        cout << " Unable to open file " << filename << endl;
    }
}