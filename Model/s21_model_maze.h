#ifndef SRC_MODEL_S21_MODEL_MAZE_H
#define SRC_MODEL_S21_MODEL_MAZE_H

#include <string>
#include <vector>

namespace s21 {

class ModelMaze {
public:
    using MazeMatrix = std::vector<std::vector<bool>>;

    explicit ModelMaze() = default;
    ModelMaze(std::string &model_path);
    ModelMaze(size_t width, size_t height);
    ~ModelMaze() = default;

    size_t GetHeight() const noexcept;
    size_t GetWidth() const noexcept;

//private:
    void ParseFromFile(const std::string &model_path);
    void InitMatrix(std::ifstream &fin, MazeMatrix &matrix);
    void InvalidFileThrow();
    void SetMatrixDimension(std::ifstream &fin, size_t &d);
    void printMatrix();

    size_t width_;
    size_t height_;
    MazeMatrix horizontal_walls_;
    MazeMatrix vertical_walls_;
};

}  // namespace s21

#endif // SRC_MODEL_S21_MODEL_MAZE_H
