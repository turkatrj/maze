#ifndef SRC_CONTROLLER_S21_CONTROLLER_MAZE_H
#define SRC_CONTROLLER_S21_CONTROLLER_MAZE_H

#include "../Model/s21_model_maze.h"


namespace s21 {

class ControllerMaze {
public:
    explicit ControllerMaze(ModelMaze* ptr);
    ~ControllerMaze();

private:
    ModelMaze* model_;

};

}  // namespace s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_MAZE_H
