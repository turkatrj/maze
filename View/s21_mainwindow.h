#ifndef SRC_VIEW_MAINWINDOW_H
#define SRC_VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "s21_graphicscene.h"
#include "../Controller/s21_controller_cave.h"
#include "../Controller/s21_controller_maze.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCaveWidthSliderValueChanged(int value);
    void onMazeWidthSliderValueChanged(int value);
    void onMazeHeightSliderValueChanged(int value);
    void onCaveHeightSliderValueChanged(int value);
    void onBirthSliderValueChanged(int value);
    void onDeathSliderValueChanged(int value);

    void openFile();

    ControllerCave* getControllerCave();
    ControllerMaze* getControllerMaze();

private:
    ControllerCave* controller_cave_;
    ControllerMaze* controller_maze_;
    GraphicScene *scene_;
    Ui::MainWindow *ui_;


};

}  // namespace s21

#endif // SRC_VIEW_MAINWINDOW_H
