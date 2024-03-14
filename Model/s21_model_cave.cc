#include "s21_model_cave.h"


namespace s21 {

ModelCave::ModelCave() {

    openFile("/home/turkartj/maze_test/Tests/cave_test.txt");




}

ModelCave::~ModelCave() {}

int ModelCave::openFile(std::string filepath) {
    std::ifstream cave_file(filepath);
    error_ = 0;
    size_n_ = 0;
    size_m_ = 0;

    if (!cave_file.is_open()) {
        std::cout << "Cant open file!\n";
        error_ = 1;
    } else {
        std::string line;

        while(!cave_file.eof() && !error_) {
            cave_file >> size_n_;
            cave_file >> size_m_;

            if (size_n_ > 0 & size_n_ <= 50 && size_m_ > 0 & size_m_ <= 50) {
                std::cout << "Lets parsing! " << size_n_ << " " << size_m_ << "\n";

                data_ = new int*[size_n_];

                for (int i = 0; i < size_n_ && !cave_file.eof(); ++i) {
                    data_[i] = new int[size_m_];
                    for (int j = 0; j < size_m_ && !cave_file.eof(); ++j) {
                        cave_file >> data_[i][j];
                    }
                }

                printArray(data_);
                break;
            } else {
                std::cout << "BAD SIZES!\n" << size_n_ << " " << size_m_ << "\n";
                error_ = 2;
            }
        }
        cave_file.close();
    }

    return error_;
}





int ModelCave::getSizeN() {
    return size_n_;
}


int ModelCave::getSizeM() {
    return size_m_;
}

int** const ModelCave::getData() {
    return data_;
}



void ModelCave::printArray(int **arr) {
    for (int i = 0; i < size_n_; ++i) {
        for (int j = 0; j < size_m_; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

}  // namespace s21
