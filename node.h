#pragma once

#include <iostream>

struct Node {
    std::string data;
    Node* next;
    Node* prev;

    Node(const std::string& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {
    }
};

struct Node2 {
    std::string key; // значение узла
    Node2* left; // указатели на левые и правые дочерние узлы
    Node2* right;
    int height; // высота узла
    // инициализируем дерево
    Node2(std::string value) : key(value), left(nullptr), right(nullptr), height(1) {}
};