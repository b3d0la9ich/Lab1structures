#pragma once 
#include <iostream>
#include <string>

using namespace std;

struct Node{
    string item;
    Node* next;

    Node(string _item) : item(_item), next(nullptr) {}
};

struct singlyList {
    Node* first;
    Node* last;
    singlyList() : first(nullptr), last(nullptr) {}

    ~singlyList(){ // освобождаем память
        while(first){
            Node* newNode = first;
            first = first->next;
            delete newNode;
        }
    }

    bool is_empty() { // пустой ли список
        return first == nullptr; // если первый узел пустой, то список пуст
    }

    void addToEnd(string _item){ // добавление нового узла в конец списка
        Node* newNode = new Node(_item); // создаем новый узел с заданным значением
        if (is_empty()){ // если список пустой
            first = newNode;
            last = newNode;
            return;
        }
        last->next = newNode; // новый узел добавляется в конец
        last = newNode; // и становится последним (указатель на новый узел)
    }

    void addToStart(string _item){ // добавление нового узла в начало списка
        Node* newNode = new Node(_item); // создаем новый узел с заданным значением
        if (is_empty()){
            first = newNode;
            last = newNode;
        }
        newNode->next = first; // новый узел привязывается к старому первому элементу
        first = newNode; // и становится первым 
    }

    void delFromEnd(){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        if (first == last){
            //delFromHead();
            return;
        }
        Node* newNode = first; // создаем указатель на первый узел
        while (newNode->next != last){ // ищем предпоследний узел
            newNode = newNode->next;
        }
        newNode->next = nullptr; //предпоследний узел теперь указывает на nullptr
        delete last; // удаляем последний узел
        last = newNode; // предпоследний узел становится последним
    }

    void delFromHead(){
        if (is_empty()){
            cout << "List is empty" << endl;
        }
        Node* newNode = first; // новый узел становится первым
        first = newNode->next; // голова указывает на второй узел
        delete newNode; // удаляет старый первый узел
    }

    void delItem(string _item){
        // в разработке
    }

    void findItem(string _item){
        // в разработке
    }

    void findIndex(int index){
        // в разработке
    }

    void printList(){
        // в разработке
    }

    void loadFromFile(const string& file){
        // в разработке
    }
    
    void saveToFile(const string& file){
        // в разработке
    }

    void clear(){
        // в разработке
    }
};