#ifndef SRC_VIEW_GRAPHICSCENE_H
#define SRC_VIEW_GRAPHICSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "../Controller/s21_controller_cave.h"
#include "../Controller/s21_controller_maze.h"

namespace s21 {

class GraphicScene : public QGraphicsScene
{
public:
    explicit GraphicScene(QWidget *ui, ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_);
    ~GraphicScene();

private:
    QWidget *ui_;
    s21::ControllerCave* controller_cave_;
    s21::ControllerMaze* controller_maze_;
    std::pair<int, int> cave_size_;
    std::pair<int, int> maze_size_;
};

}  // namespace s21

#endif // SRC_VIEW_GRAPHICSCENE_H
