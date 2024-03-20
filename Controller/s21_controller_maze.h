#ifndef SRC_CONTROLLER_S21_CONTROLLER_MAZE_H
#define SRC_CONTROLLER_S21_CONTROLLER_MAZE_H

#include <utility>

#include "../Model/s21_model_maze.h"

namespace s21 {

class ControllerMaze {
public:
    ControllerMaze(ControllerMaze const &other) = delete;  /// Should't be cloned.
    void operator=(const ControllerMaze &) = delete;   /// Should't be assignable.

    static ControllerMaze *Get();
    ~ControllerMaze();

    std::pair<int, int> ProcessModelFromFile(const std::string &model_path);

private:
    static ControllerMaze *instance_;
    ModelMaze* model_;
    ControllerMaze();
};

}  // namespace s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_MAZE_H
