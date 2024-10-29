#include <iostream>
#include <fstream>

#include "header.h"
#include "node.h"

using namespace std;

void CBTree::insert(int digit){
    TreeNode* newNode = new TreeNode(digit);
    if (root == nullptr){
        root = newNode;
        return;
    }
    QueueTree Q; // используем для обхода в ширину
    Q.enqueue(root); // помещаем корень в очередь Q
    while (!Q.is_empty()) {
        TreeNode* current = Q.dequeue();
        if (current->left == nullptr){
            current->left = newNode;
            return;
        } else {
            Q.enqueue(current->left);
        }
        if (current->right == nullptr) {
            current->right = newNode;
            return;
        } else {
            Q.enqueue(current->right);
        }
    }
}

bool CBTree::is_CBT() {
    if (root == nullptr) {
        cout << "Tree is empty";
        return false;
    }

    QueueTree Q;
    Q.enqueue(root);
    bool non_full_node = false;
    while (!Q.is_empty()) {
        TreeNode* current = Q.dequeue();

        if (current->left){
            if (non_full_node){
                return false;
            }
            Q.enqueue(current->left);
        } else {
            non_full_node = true;
        }

        if (current->right) {
            if (non_full_node) {
                return false;
            }
            Q.enqueue(current->right);
        } else {
            non_full_node = true;
        }
    }
    return true;
}

bool CBTree::find_value(TreeNode* current, int value) {
    if (current == nullptr) {
        return false;
    }
    if (current->digit == value) {
        return true;
    }
    return find_value(current->left, value) || find_value(current->right, value);
}

bool CBTree::get_value(int value) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return false;
    }
    return find_value(root, value);
}

void CBTree::find_index(int index) {
    if (index < 0) {
        cout << "Invalid index" << endl;
        return;
    }

    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }

    QueueTree Q;
    Q.enqueue(root);
    int currentIndex = 0;

    while (!Q.is_empty()){
        TreeNode* current = Q.dequeue();
        if (currentIndex == index) {
            cout << "Value: " << current->digit << endl;
            return;
        }
        currentIndex++;
        if (current->left) {
            Q.enqueue(current->left);
        }
        if (current->right){
            Q.enqueue(current->right);
        }
    }
    cout << "Value not founded" << endl;
}

// Вывод обхода
void CBTree::print_CBT(TreeNode* current, int level) {
    if (current) {
        print_CBT(current->right, level + 1);
        for (int i = 0; i < level; i++){
            cout << "   ";
        }
        cout << current->digit << endl;
        print_CBT(current->left, level + 1);
    }
}

void CBTree::display(){
    if (root == nullptr) {
        cout << "Tree is emopty" << endl;
        return;
    }
    print_CBT(root, 0);
}

// Чтение из файла
void CBTree::loadFromFile(const string& file) {
    ifstream load(file);
    if (!load) {
        cout << "Failed to open file.\n";
        return;
    }

    int value;
    while (load >> value) {
        insert(value);
    }
    load.close();
}

// Запись в файл
void CBTree::saveToFile(const string& file) {
    ofstream save(file);
    if (!save) {
        cout << "Failed to open file.\n";
        return;
    }

    QueueTree Q;
    Q.enqueue(root);
    while (!Q.is_empty()) {
        TreeNode* current = Q.dequeue();
        save << current->digit << endl;
        if (current->left) {
            Q.enqueue(current->left);
        }
        if (current->right) {
            Q.enqueue(current->right);
        }
    }
    save.close();
}