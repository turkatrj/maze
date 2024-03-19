#include "s21_graphicscene.h"


namespace s21 {

GraphicScene::GraphicScene(QWidget *ui, ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_)
    : ui_(ui), controller_cave_(cntr_cave_), controller_maze_(cntr_maze_)
{

    QGraphicsTextItem *textItem = new QGraphicsTextItem("Get Ready!");
    textItem->setDefaultTextColor(Qt::white);
    addItem(textItem);
    addLine(0, 250, 0, -250);
    addLine(250, 0, -250, 0);


    int** data = controller_cave_->getData();
    cave_size_ = controller_cave_->getSize();


    int step_x = 500.0 /cave_size_.first;
    int step_y = 500.0 / cave_size_.second;



    for (int i = 0; i < cave_size_.first; ++i) {


        for (int j = 0; j < cave_size_.second; ++j) {
          //  std::cout << " data[" << i << "][" << j << "] = " << data[i][j] << "\n";
            if (data[i][j] > 0) {
                addRect(step_x * i - 250, step_y * j  - 250, step_x, step_y, QPen(), QBrush(Qt::black));
            } else {
                addRect(step_x * i - 250, step_y * j  - 250, step_x, step_y, QPen(), QBrush(Qt::white));
            }
        }







    }



}

GraphicScene::~GraphicScene() {}

}  // namespace s21
