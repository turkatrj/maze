#include "View/s21_mainwindow.h"

#include <QApplication>

#include "Controller/s21_controller_maze.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    s21::ModelCave model_cave;
    s21::ModelMaze model_maze;
    s21::ControllerCave controller_cave(&model_cave);
    s21::ControllerMaze *controller_maze = s21::ControllerMaze::Get();
    s21::MainWindow w;
    w.show();
    return a.exec();
}
