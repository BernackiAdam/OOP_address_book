#ifndef BASEFILEMANAGER_H
#define BASEFILEMANAGER_H

#include <iostream>
#include <fstream>
using namespace std;

class BaseFileManager {
public:
    bool isFileEmpty(const string& fileName) {
        ifstream file(fileName, ios::in);
        bool isEmpty = file.peek() == ifstream::traits_type::eof();
        file.close();
        return isEmpty;
    }
};

#endif