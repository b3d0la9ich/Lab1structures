#pragma once 
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(const string& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
};

struct DoublyNode {
    string data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(const string& value, DoublyNode* nextNode = nullptr, DoublyNode* prevNode = nullptr) : data(value), next(nextNode), prev(prevNode) {}
};

struct HashNode {
    string key;
    string value;
    HashNode* next;

    HashNode(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

struct TreeNode { // узел бинарного дерева
    int digit;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int dig) : digit(dig), left(nullptr), right(nullptr) {}
};

struct QueueNode { // узел очереди
    TreeNode* tree; // указатель на узел бинарного дерева
    QueueNode* next;
};

struct QueueTree { // очередь для работы с узлами деревьев
    QueueNode* front;
    QueueNode* rear;
    int count;

    QueueTree() : front(nullptr), rear(nullptr), count(0) {}

    bool is_empty(){
        return count == 0;
    }

    void enqueue(TreeNode* node) { // добавляет узел дерева в конец очереди
        QueueNode* newNode = new QueueNode();
        newNode->tree = node;   
        newNode->next = nullptr;

        if (rear == nullptr){ // если очередь пуста
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    TreeNode* dequeue() { // удаляет узел из начала очереди и возвращает указатель на дерево
        if (is_empty()){
            return nullptr;
        }

        QueueNode* newNode = front;
        TreeNode* res = front->tree;
        front = front->next;

        if (front == nullptr){
            rear = nullptr;
        }

        delete newNode;
        count--;
        return res;
    }
};