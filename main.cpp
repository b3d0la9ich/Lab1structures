#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#include "node.h"
#include "header.h"

using namespace std;

map<string, Stack> stacks;
map<string, Queue> queues;

void commands(const string& query){

    stringstream ss(query);
    string comm;
    ss >> comm;


    //StackBro
    if (comm == "Spush"){
        string stackName;
        string item;
        ss >> stackName >> item;
        stacks[stackName].push(item);
    }
    else if (comm == "Spop"){
        string stackName;
        ss >> stackName;
        stacks[stackName].pop();
    }
    else if (comm == "Sread"){
        string stackName;
        ss >> stackName;
        stacks[stackName].display();
    }

    //QueueBro
    else if(comm == "Qpush"){
        string queueName;
        string value;
        ss >> queueName >> value;
        queues[queueName].push(value);
    }
    else if(comm == "Qpop"){
        string queueName;
        string value;
        ss >> queueName;
        queues[queueName].pop();
    }
    else if(comm == "Qread"){
        string queueName;
        ss >> queueName;
        queues[queueName].display();
    }

}

void loadFromFile(const string& filename){
    ifstream file(filename);
    if (!file){
        cout << "Cant open file:" << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)){
        commands(line);
    }
    file.close();
}

void saveToFile(const string& filename){
    ofstream file(filename);
    if (!file){
        cout << "Cant open file: " << filename << endl;
    }

    for (const auto&[name, stack] : stacks){
        Node* current = stack.top;
        while (current != nullptr){
            file << name << " " << current->data << endl;
        }
    }

    file.close();
}

int main(int argc, char* argv[]){

    string filename;

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file") {
            if (i + 1 < argc) {
                filename = argv[++i];
            }
        }
    }

    // Загружаем данные из файла
    if (!filename.empty()) {
        loadFromFile(filename);
    }

    // Интерактивный ввод команд
    string query;
    cout << "Enter command (or 'exit for close terminal'):" << endl;
    while (true) {
        cout << "> ";
        getline(cin, query);
        if (query == "exit") {
            break; // Выход из цикла
        }
        commands(query);
    }

    // Сохраняем данные обратно в файл
    if (!filename.empty()) {
        saveToFile(filename);
    }

    return 0;
}