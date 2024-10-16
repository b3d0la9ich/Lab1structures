#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct tNode {
    int digit;
    tNode* left;
    tNode* right;

    tNode(int dig) : digit(dig), left(nullptr), right(nullptr) {}
};

struct queueNode {
    tNode* tree; // указатель на узел дерева
    queueNode* next; // указатель на след узел
};

struct qTree { // очередь для дерева
    queueNode* front; // указатель на голову
    queueNode* back; // указатель на хвост
    int count; // кол-во узлов в очереди

    qTree() : front(nullptr), back(nullptr), count(0) {}

    bool is_empty(){
        return count == 0;
    }

    void enqueue(tNode* node){ // добавление узла в очередь
        queueNode* newNode = new queueNode(); // новый узел
        newNode->tree = node;
        newNode->next = nullptr;
        if (back == nullptr){
            front = back = newNode;
        }
        else{
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    tNode* dequeue() { // удаление из очереди
        if (is_empty()){
            return nullptr;
        }
        queueNode* newNode = front;
        tNode* res = front->tree;
        front = front->next;
        if (front == nullptr){
            back = nullptr;
        }
        delete newNode;
        count--;
        return res;
    }
};

struct CBT {
    tNode* root; // указатель на корень
    CBT() : root(nullptr) {}

    void insert(int digit){ // добавление нового узла
        tNode* newNode = new tNode(digit);
        if (root == nullptr){
            root = newNode; // если дерево пустое, новый узел становится корнем
            return;
        }
        qTree Q; // очередь для дерева
        Q.enqueue(root); // добавляет корень в очередь
        while (!Q.is_empty()){
            tNode* current = Q.dequeue(); // вытаскиваем значение из очереди
            if (current->left == nullptr){ // если левый узел пустой, записываем туда новое значение
                current->left = newNode;
                return;
            }
            else {
                Q.enqueue(current->left); // иначе отправляем его в очередь
            }
            if (current->right == nullptr){ // если правый узел пустой, записываем туда новое значение
                current->right = newNode;
                return;
            }
            else {
                Q.enqueue(current->right); // иначе отправляем его в очередь
            }
        }
    }

    void printCBT(tNode* current, int level){
        if (current) {
            printCBT(current->right, level + 1); // начинаем с правого узла
            for (int i = 0; i < level; i++){
                cout << " "; // вывод нужного количества табуляции
            }
            cout << current->digit << endl;
            printCBT(current->left, level + 1); // обработка левых узлов
        }
    }

    void printTree() {
        if (root == nullptr){
            cout << "Tree is empty.\n";
            return;
        }
        printCBT(root, 0);
    }

    bool isCBT() { // проверка на cbt
        if (root == nullptr) { // если дерево пустое
            cout << "Tree is empty.\n";
            return false;
        }
        qTree Q; // очередь
        bool nonFullNode = false; // флаг - узел, у которого отсутствует хотя бы один потомок
        while (!Q.is_empty()){
            tNode* current = Q.dequeue(); // указатель на текущее значение
            if (current->left){ // проверка левого потомка
                if (nonFullNode){ // если уже был найден узел без потомка до этого - дерево не полное
                    return false;
                }
                Q.enqueue(current->left);
            }
            else{
                nonFullNode = true;
            }
            if (current->right) { // проверка правого потомка
                if (nonFullNode) { // если уже был найден узел без потомка до этого - дерево не полное
                    return false;
                }
                Q.enqueue(current->right);
            }
            else{
                nonFullNode = true;
            }
        }
        return true;
    }

    bool findValue(tNode* current, int val){ // поиск элемента по значению
        if (current == nullptr) { // если узлы кончились и элемент не найден
            return false;
        }
        if (current->digit == val) { // если элемент найден
            return true;
        }
        return findValue(current->left, val) || findValue(current->right, val); // рекурсия
    }

    bool findVal(int val) { // функция для вызова из main
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return false;
        }
        return findValue(root, val);
    }

    void findIndex(int index) { // чтение (поиск по индексу)
        if (index < 0) { // проверка на корректный индекс
            cout << "Wrong index\n";
            return;
        }
        if (root == nullptr) { // проверка на пустоту
            cout << "Tree is empty\n";
            return;
        }
        qTree Q; // очередь
        Q.enqueue(root); // начинаем обход с корня
        int currentIndex = 0; // текущий индекс
        while (!Q.is_empty()) {
            tNode* current = Q.dequeue(); // текущий узел
            if (currentIndex == index) { // индекс найден
                cout << "Element by index: " << current->digit << endl;
                return;
            }
            currentIndex++; // увеличиваем текущий индекс
            if (current->left) { // левый потомок
                Q.enqueue(current->left);
            }
            if (current->right) { // правый потомок
                Q.enqueue(current->right);
            }
        }
        cout << "Element didnt find\n";
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
        clear(root);
        ifstream load(file);
        if (!load) {
            cout << "Cant open the file\n";
            return;
        }
        int value;
        while (load >> value) {
            insert(value); // добавляем элементы
        }
        load.close();
    }

    void saveToFile(const string& file) { // сохранение в файл
        ofstream save(file);
        if (!save) {
            cout << "Cant open the file\n";
            return;
        }
        qTree Q; // очередь
        Q.enqueue(root); // начинаем обход с корня
        while (!Q.is_empty()) {
            tNode* current = Q.dequeue(); // текущий узел
            save << current->digit << endl; 
            if (current->left) { // левый потомок
                Q.enqueue(current->left);
            }
            if (current->right) { // правый потомок
                Q.enqueue(current->right);
            }
        }
        save.close();
    }

    void clear(tNode*& node) { // рекурсивное удаление всех узлов
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }
};