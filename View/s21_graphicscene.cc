#include "s21_graphicscene.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "../Controller/s21_controller_maze.h"

namespace s21 {

GraphicScene::GraphicScene(Ui::MainWindow *ui) noexcept
    : ui_(ui)
{
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Get Ready!");
    textItem->setDefaultTextColor(Qt::white);
    addItem(textItem);
}

GraphicScene::~GraphicScene() {}

void GraphicScene::DrawFromFile(const std::string &model_path)
{
    InitSize(model_path);
    Draw();
}

void GraphicScene::InitSize(const std::string &model_path) {
    auto size = s21::ControllerMaze::Get()->ProcessModelFromFile(model_path);
    height_ = size.first;
    width_ = size.second;
    ui_->maze_height_slider->setValue(height_);
    ui_->maze_width_slider->setValue(width_);
    SetSteps();
}

void GraphicScene::SetSteps() { step_x_ = 500 /width_; step_y_ = 500 / height_; }

void GraphicScene::Draw() {
    clear();
    addRect(0, 0, height_, width_);
    for (auto i = 0; i < height_; ++i) {
        for (auto j = 0; j < width; ++j_) {

        }
    }
}

}  // namespace s21
