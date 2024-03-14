#include "s21_graphicscene.h"


namespace s21 {

GraphicScene::GraphicScene(QWidget *ui, ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_)
    : ui_(ui), controller_cave_(cntr_cave_), controller_maze_(cntr_maze_)
{
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Get Ready!");
    textItem->setDefaultTextColor(Qt::white);
    addItem(textItem);
}

GraphicScene::~GraphicScene() {}

}  // namespace s21
