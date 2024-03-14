#include "s21_controller_cave.h"


namespace s21 {

ControllerCave::ControllerCave(ModelCave* ptr) : model_(ptr) {

}

ControllerCave::~ControllerCave() {}

std::pair<int, int> ControllerCave::getSize() {
    return std::pair<int, int>(model_->getSizeN(), model_->getSizeN());
}

int** const ControllerCave::getData() {
    return model_->getData();
}

}  // namespace s21
