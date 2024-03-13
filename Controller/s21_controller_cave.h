#ifndef SRC_CONTROLLER_S21_CONTROLLER_CAVE_H
#define SRC_CONTROLLER_S21_CONTROLLER_CAVE_H

#include "../Model/s21_model_cave.h"


namespace s21 {

class ControllerCave {
public:
    explicit ControllerCave(ModelCave* ptr);
    ~ControllerCave();

private:
    ModelCave* model_;

};

}  // namespace s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_CAVE_H
