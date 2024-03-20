#ifndef SRC_VIEW_GRAPHICSCENE_H
#define SRC_VIEW_GRAPHICSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QPen>

#include "forms/ui_s21_mainwindow.h"

namespace s21 {

class GraphicScene : public QGraphicsScene
{
public:
    explicit GraphicScene(Ui::MainWindow *ui) noexcept;
    ~GraphicScene();

    void DrawFromFile(const std::string &model_path);
    void Draw();
    void InitSize(const std::string &model_path);
    void SetSteps();

private:
    Ui::MainWindow *ui_;
    size_t height_;
    size_t width_;
    double step_x_;
    double step_y_;
    QPen pen_;
};

class MazeScene: GraphicScene {
public:
    explicit MazeScene(QWidget *ui) noexcept;
    ~MazeScene();

private:

};

}  // namespace s21

#endif // SRC_VIEW_GRAPHICSCENE_H
