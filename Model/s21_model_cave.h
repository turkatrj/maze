#ifndef SRC_MODEL_S21_MODEL_CAVE_H
#define SRC_MODEL_S21_MODEL_CAVE_H

#include <fstream>
#include <iostream>
#include <stdio.h>

namespace s21 {

class ModelCave {
public:
    explicit ModelCave();
    ~ModelCave();
    int openFile(std::string filepath);
    int getSizeN();
    int getSizeM();
    int** const getData();

private:
    void printArray(int** arr);

private:
    int error_;
    int size_n_;
    int size_m_;
    int** data_;


};

}  // namespace s21

#endif // SRC_MODEL_S21_MODEL_CAVE_H
