#pragma once 
#include <iostream>
#include <string>
#include <fstream>

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
            delFromHead();
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
            return;
        }
        Node* newNode = first; // новый узел становится первым
        first = newNode->next; // голова указывает на второй узел
        delete newNode; // удаляет старый первый узел
    }

    void delItem(string _item){ // удаляет узел по значению
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }

        if (first->item == _item) {
            delFromHead();
            return;
        }

        if (last->item == _item) {
            delFromEnd();
            return;
        }

        Node* prev = first;
        Node* curr = first->next;
        while (curr && curr->item != _item){ // пока второй указатель не указывает на nullptr или не равен искомому
            curr = curr->next;
            prev = prev ->next;
        }

        if (!curr) { // если элемент не найден или указатель указывает на nullptr
            cout << "Element not on the list" << endl;
            return;
        }
        prev->next = curr->next; // предыдущий узел теперь указывает на узел на следущий элемент, после удаляемого
        delete curr; // удаляем искомый элемент
    }

    void findItem(string _item){ // поиск элемента по значению
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* newNode = first;
        int index = 0;
        while (newNode && newNode->item != _item){
            newNode = newNode->next;
            index++;
        }
        if (!newNode){
            cout << "Element not on the list" << endl;
            return;
        }
        cout << "Index of element: " << index << endl;
    }

    void findIndex(int index){ // поиск элемента по индексу
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* newNode = first;
        for (int i = 0; i < index && newNode; i++){ // пока текущий индекс не будет равен заданному
            newNode = newNode->next;
        }
        if (!newNode){
            cout << "Element not on the list" << endl;
        }
        cout << "Element by index: " << newNode->item << endl;
    }

    void printList(){
        if (is_empty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* newNode = first;
        while (newNode) {
            cout << newNode->item << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }

    void loadFromFile(const string& file){ // загрузка данных из файла
        while (first) { // очищаем текущий лист
            delFromHead();
        }
        ifstream load(file);
        if (!load) {
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
        if (!save) {
            cout << "Cant open the file" << endl;
            return;
        }
        Node* newNode = first;
        while (newNode){ 
            save << newNode->item << endl;
            newNode = newNode->next;
        }
        save.close();
        const_cast<singlyList*>(this)->clear();
    }

    void clear(){
        while (first){
            delFromHead();
        }
    }
};