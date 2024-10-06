#include "header.h"
#include "node.h"

using namespace std;

void Stack::push(string value){
    Node* node = new Node(value);
    if (top == nullptr){
        top = node;
    }
    else{
        node->next = top;
        top = node;
    }
}

void Stack::pop(){
    if (top == nullptr){
        cout << "Stack is empty" << endl;
        cout << "Cant delete anything" << endl;
    }
    else{
        Node* temp = top;
        top = top->next;
        cout << "Deleted object: " << temp->data << endl;
        delete temp;
    }
}

void Stack::display(){
    if (top == nullptr){
        cout << "Stack is empy" << endl;
        cout << "Cant display anything" << endl;
    }
    else{
        cout << "Elements of stack: " << endl;
        Node* current = top;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}