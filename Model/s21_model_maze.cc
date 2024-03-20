#include "s21_model_maze.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <QDebug>

namespace s21 {

void ModelMaze::ParseFromFile(const std::string &model_path) {
    std::ifstream fin(model_path);
    if (!fin) throw std::runtime_error("Failed to open file: " + model_path);
    if (fin.peek() == fin.eof()) InvalidFileThrow();
    else {
        SetMatrixDimension(fin, height_);
        SetMatrixDimension(fin, width_);
        InitMatrix(fin, vertical_walls_);
        InitMatrix(fin, horizontal_walls_);
        fin.close();
    }
}

void ModelMaze::SetMatrixDimension(std::ifstream &fin, size_t &d) {
    fin >> d;
    if (fin.fail() || d <= 0) InvalidFileThrow();
}

void ModelMaze::InitMatrix(std::ifstream &fin, MazeMatrix &matrix) {
    int data;
    matrix.resize(height_, std::vector<bool>(width_, false));
    for (size_t i = 0; i < height_; ++i) {
    for (size_t j = 0; j < width_; ++j) {
        fin >> data;
        if(data != 1 && data != 0) InvalidFileThrow();
        vertical_walls_[i][j] = data;
    }
    }
}

void ModelMaze::InvalidFileThrow() { throw std::runtime_error("File is invalid."); }

size_t ModelMaze::GetHeight() const noexcept { return height_; }
size_t ModelMaze::GetWidth() const noexcept { return width_; }

}  // namespace s21
