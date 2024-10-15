#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Array {
    string* arr; // динамический массив строк
    size_t size; // текущий размер
    size_t capacity; // максимальный размер

    Array(size_t cap = 15) : size(0), capacity(cap) {
        arr = new string[capacity]; // выделение памяти
    }

    ~Array() {
        delete[] arr; // освобождение памяти
    }

    void resize(){
        capacity *= 2; // увеличивает максимальный размер в 2 раза
        string* newArr = new string[capacity];
        for (size_t i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void addByIndex(const string& item, size_t index){
        if (index >= size){
            cout << "Error index" << endl;
            return;
        }
        if (size >= capacity) {
            resize();
        }
        for (size_t i = size; i > index; --i){ // сдвигаем элемент с конца вправо
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        size++;
    }

    void addToEnd(const string& item){
        if (size >= capacity){
            resize();
        }
        arr[size++] = item; // добавляем элемент в конец
    }

    void findByIndex(size_t index){
        if (size == 0){
            cout << "Array is empty" << endl;
            return;
        }
        if (index >= size){
            cout << "Error index" << endl;
            return;
        }
        cout << "Element by index: " << arr[index] << endl;
    }

    void delByIndex(size_t index){
        if (size == 0){
            cout << "Array is empty" << endl;
            return;
        }
        if (index >= size){
            cout << "Error index" << endl;
            return;
        }
        for (size_t i = index; i < size - 1; i++){ // сдвигаем элементы влево на один
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void replace(size_t index, const string& item){
        if (size == 0){
            cout << "Array is empty" << endl;
            return;
        }
        if (index >= size){
            cout << "Error index" << endl;
            return;
        }
        arr[index] = item; // замена
    }

    void length(){
        cout << "Length of array: " << size << endl;
    }

    void findByItem(const string& item) { // чтение (поиск элемента по значению)
        if (size == 0) { // проверка на пустоту
            cout << "Array is empty\n";
            return;
        }
        for (size_t i = 0; i < size; i++) { // проходимся по массиву
            if (arr[i] == item) {
                cout << "Index of element: " << i << endl;
                return;
            }
        }
        cout << "No such element\n";
    }

    void printArray(){
        if (size == 0){
            cout << "Array is empty\n";
            return;
        }
        for (size_t i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void loadFromFile(const string& file){
        size = 0; // очищаем массив
        ifstream load(file);
        if (!load.is_open()) { // проверка
            cout << "Cant open the file\n";
            return;
        }
        string str; // текущая строка данных
        while (getline(load, str)) {
            addToEnd(str); // добавляем в конец массива
        }
        load.close();
    }

    void saveToFile(const string& file) { // загрузка данных в файл
        ofstream save(file);
        if (!save.is_open()) { // проверка
            cout << "Cant open the file\n";
            return;
        }
        for (size_t i = 0; i < size; ++i) { // запись в файл
            save << arr[i] << endl;
        }
        save.close();
        const_cast<Array*>(this)->size = 0; // очистка массива
    }
};