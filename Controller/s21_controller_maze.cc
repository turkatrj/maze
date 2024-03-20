#include "s21_controller_maze.h"

#include <utility>

namespace s21 {

ControllerMaze *ControllerMaze::instance_= nullptr;

ControllerMaze::ControllerMaze() : model_(new s21::ModelMaze) {}

ControllerMaze::~ControllerMaze() {
    delete model_;
}

ControllerMaze *ControllerMaze::Get() {
    if (instance_ == nullptr) instance_ = new ControllerMaze;
    return instance_;
}

std::pair<int, int> ControllerMaze::ProcessModelFromFile(const std::string &model_path)
{
    model_->ParseFromFile(model_path);
    return std::make_pair(model_->GetHeight(), model_->GetWidth());
}

}  // namespace s21
