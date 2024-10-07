#include "node.h"
#include "header.h"

using namespace std;

void Queue::push(string value){
    Node* node = new Node{value, nullptr};
    if(head == nullptr){
        head = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
}

void Queue::pop(){
    if (head == nullptr){
        cout << "Queue is empty" << endl;
        cout << "Cant delete anything" << endl;
    }
    else{
        Node* temp = head;
        head = head->next;
        cout << "Deleted object: " << temp->data << endl;
        delete temp;
    }
}

void Queue::display(){
    if (head == nullptr){
        cout << "Queue is empty" << endl;
        cout << "Cant display anything" << endl;
    }
    else{
        cout << "Elements of queue" << endl;
        Node* current = head;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}