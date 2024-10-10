#include "node.h"
#include "header.h"

void Array::add(int index, string value){
    if (index < 0 || index > size){
        cout << "Cant add new elenemnt" << endl;
        cout << "Error index" << endl;
        return;
    }
    if (size > capacity){
        cout << "Cant add new element" << endl;
        cout << "The maximum size has been reached" << endl;
        return;
    }

    Node* newNode = new Node(value);
    if (index == 0){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* current = head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

void Array::addToEnd(string value){
    add(size, value);
}

string Array::get(int index){
    if (index < 0 || index > size){
        cout << "Cant get an element" << endl;
        cout << "Error index" << endl;
        return "";
    }
    Node* current = head;
    for(int i = 0; i < index; i++){
            current = current->next;
    }
    return current->data;
}

void Array::remove(int index){
    if (index < 0 || index > size){
        cout << "Cant remove an element" << endl;
        cout << "Error index" << endl;
        return;
    }
    Node* toDelete = nullptr;
    if (index == 0){
        toDelete->next = head;
        head = head->next;
    }
}

void Array::replace(int index, string value){
    if (index < 0 || index >= size){
        cout << "Cant replace elements" << endl;
        cout << "Wrong index" << endl;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++){
        current = current->next;
    }
    current->data = value;
}

int Array::length(){
    return size;
}

void Array::display(){
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}