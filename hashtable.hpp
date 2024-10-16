#pragma once 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int tableSize = 100;

struct hNode { // структура таблицы
    string key;
    string item; 
    hNode* next;
};

struct hashTable {
    hNode** table;

    hashTable() {
        table = new hNode* [tableSize]; // выделение памяти под массив указателей
        for (int i = 0; i < tableSize; i++){
            table [i] = nullptr;
        }
    }
};