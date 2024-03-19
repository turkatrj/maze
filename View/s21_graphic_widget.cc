#include "s21_graphic_widget.h"


namespace s21 {

GraphicWidget::GraphicWidget(QWidget *ui, ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_)
    : ui_(ui), controller_cave_(cntr_cave_), controller_maze_(cntr_maze_)
{


    scene_ = new QGraphicsScene();

   // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
   // setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    //setBackgroundBrush(Qt::white);  // цвет фона


    setSceneRect(-250, -250, 500, 500);
    setScene(scene_);


    /*
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Get Ready!");
    textItem->setDefaultTextColor(Qt::white);
    scene_->addItem(textItem);

    scene_->addLine(0, 250, 0, -250);
    scene_->addLine(250, 0, -250, 0);
    scene_->addRect(0, 0, 100, 50, QPen(Qt::red), QBrush(Qt::green));
    */
    //scene_->addRect(-250, -250, 125, 125, QPen(), QBrush(Qt::black));




    drawMaze();
    drawCave();



}

GraphicWidget::~GraphicWidget() {}

void GraphicWidget::drawCave() {
    scene_->clear();
    items().clear();

    int** data = controller_cave_->getData();
    cave_size_ = controller_cave_->getSize();

    int step_x = 500.0 /cave_size_.first;
    int step_y = 500.0 / cave_size_.second;


    for (int i = 0; i < cave_size_.first; ++i) {
        for (int j = 0; j < cave_size_.second; ++j) {
         //   std::cout << " data[" << i << "][" << j << "] = " << data[i][j] << "\n";
            if (data[i][j]) {
                scene_->addRect(step_x * i - 250, step_y * j  - 250, step_x, step_y, Qt::NoPen, QBrush(Qt::black));
            } else {
                scene_->addRect(step_x * i - 250, step_y * j  - 250, step_x, step_y, Qt::NoPen, QBrush(Qt::white));
            }
        }
       // std::cout << "\n";
    }






}

void GraphicWidget::drawMaze() {
    scene_->clear();
    items().clear();

    std::pair<int, int> maze_size = std::make_pair(4, 4);

    int step_x = 500.0 / maze_size.first;
    int step_y = 500.0 / maze_size.second;

///////////////////////////////////////  Создаем и заполняем 2 массива для теста /////////////////////

    int** maze_vertical_data = new int*[maze_size.first];
    for (int i = 0; i < maze_size.first; ++i) {
        maze_vertical_data[i] = new int[maze_size.second] {1, 0, 1, 1};
    }
    maze_vertical_data[1][0] = 0;
    maze_vertical_data[2][2] = 0;
    maze_vertical_data[2][3] = 0;

    int** maze_horizontal_data = new int*[maze_size.first];
    for (int i = 0; i < maze_size.first; ++i) {
       maze_horizontal_data[i] = new int[maze_size.second] {0, 1, 0, 1};
    }

//////////////////////////////////////////////////////////////////////////////



    QPen lines_pen(Qt::white);
    lines_pen.setWidth(2);

    //  Рамка
    scene_->addLine(-250, -250, -250, 250, lines_pen);
    scene_->addLine(-250, -250, 250, -250, lines_pen);
    scene_->addLine(250, 250, 250, -250, lines_pen);
    scene_->addLine(250, 250, -250, 250, lines_pen);
    //

    for (int i = 0; i < maze_size.first; ++i) {
        for (int j = 0; j < maze_size.second; ++j) {
         //   std::cout << " data[" << i << "][" << j << "] = " << data[i][j] << "\n";
            if (maze_vertical_data[i][j]) {
                //  {1, 0, 1, 1}
                scene_->addLine(step_x * (j + 1) - 250, step_y * i  - 250,
                                step_x * (j + 1) - 250, step_y * (i + 1)  - 250,
                                lines_pen);
            }
            if (maze_horizontal_data[i][j]) {
                //  {0, 1, 0, 1}
                scene_->addLine(step_x * j  - 250, step_y * (i + 1)  - 250,
                                step_x * (j + 1)  - 250, step_y * (i + 1)  - 250,
                                lines_pen);
            }
        }
       // std::cout << "\n";
    }

}

}  // namespace s21
