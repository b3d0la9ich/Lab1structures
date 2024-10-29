#include <iostream>
#include <fstream>

#include "node.h"
#include "header.h"

using namespace std;

HashTable::HashTable() {
    for (int i = 0; i < tablesize; i++){
        table[i] = nullptr;
    }   
}

HashTable::~HashTable(){
    for (int i = 0; i < tablesize; i++){
        HashNode* current = table[i];
        while (current)
        {
            HashNode* toDel = current;
            current = current->next;
            delete toDel;
        }
    }
}

int HashTable::hashfunction(const string& key) {
    int i = 0;
    for (int j = 0; key[j]; j++){
        i += key[j];
        i %= tablesize;
    }
    return i;
}

void HashTable::insert(const string& key, const string& value){
    int index = hashfunction(key);
    HashNode* newNode = new HashNode(key, value);

    if(!table[index]){ // если нет узла 
        table[index] = newNode; // новый узел помещается в ячейку
    } else { // если коллизия 
        HashNode* current = table[index];
        while (current){
            if (current->key == key){ // если в цепочке есть узел с совпадающим ключом
                current->value = value; // старое значение заменяется новым
                delete newNode; // удаляем временный узел
                return;
            }
            if (!current->next){ // знач последний
                current->next = newNode; // добавляем в конец
                return;
            }
            current = current->next;
        }
    }
}
void HashTable::get(const string& key){
    int index = hashfunction(key);
    HashNode* current = table[index];
    while (current){
        if (current->key == key){
            cout << "Value for key[" << key << "]" << current->value << endl;
            return;
        }
        current = current->next;
    }
}

void HashTable::remove(const string& key){
    int index = hashfunction(key);
    HashNode* curr = table[index];
    HashNode* prev = nullptr;

    while (curr){
        if (curr->key == key){
            if (prev){
                prev->next = curr->next; // удаляем узел из цепочки
            } else {
                table[index] = curr->next; // если это первый узел
            }
            delete curr; // освобождаем память
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Key doenst finded for del";
}

void HashTable::print(){
    for (int i = 0; i < tablesize; i++){
        if (table[i]){
            HashNode* curr = table[i];
            while (curr){
                cout << "{ " << curr->key << ": " << curr->value << "} ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
}

void HashTable::saveToFile(const string& filename){
    ofstream file(filename);
    if (!file){
        cout << "Cant open the file" << endl;
        return;
    }

    for (int i = 0; i < tablesize; i++){
        HashNode* curr = table[i];
        while (curr){
            file << curr->key << " " << curr->value << endl;
            curr = curr->next;
        }
    }
    file.close();
}

void HashTable::loadFromFile(const string& filename){
    ifstream file(filename);
    if (!file){
        cout << "Cant open the file" << endl;
        return;
    }

    string key, value;
    while (file >> key >> value){
        insert(key, value);
    }

    file.close();
}
