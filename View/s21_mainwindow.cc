#include "s21_mainwindow.h"
#include "s21_graphicscene.h"
#include "forms/ui_s21_mainwindow.h"

#include <QFileDialog>

namespace s21 {

MainWindow::MainWindow(ControllerCave* cntr_cave_, ControllerMaze* cntr_maze_, QWidget *parent)
    : QMainWindow(parent), controller_cave_(cntr_cave_), controller_maze_(cntr_maze_),  ui_(new Ui::MainWindow)
{
    this->setWindowTitle("Maze");
    ui_->setupUi(this);
    setFixedSize(745, 512);
    scene_ = new s21::GraphicScene(this, controller_cave_, controller_maze_);

   // ui_->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
   // ui_->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    ui_->graphicsView->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    ui_->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету


    ui_->graphicsView->setSceneRect(-250, -250, 500, 500);
    ui_->graphicsView->setScene(scene_);

    connect(ui_->maze_width_slider, &QSlider::valueChanged, this, &MainWindow::onMazeWidthSliderValueChanged);
    connect(ui_->maze_height_slider, &QSlider::valueChanged, this, &MainWindow::onMazeHeightSliderValueChanged);
    connect(ui_->cave_width_slider, &QSlider::valueChanged, this, &MainWindow::onCaveWidthSliderValueChanged);
    connect(ui_->cave_height_slider, &QSlider::valueChanged, this, &MainWindow::onCaveHeightSliderValueChanged);
    connect(ui_->birth_slider, &QSlider::valueChanged, this, &MainWindow::onBirthSliderValueChanged);
    connect(ui_->death_slider, &QSlider::valueChanged, this, &MainWindow::onDeathSliderValueChanged);
    connect(ui_->load_file_maze_button, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(ui_->load_file_cave_button, SIGNAL(clicked()), this, SLOT(openFile()));
}


MainWindow::~MainWindow() {
    delete ui_;
}


void MainWindow::openFile() {
    QFileDialog::getOpenFileName(this, "Load a file", QDir::currentPath());
}

ControllerCave *MainWindow::getControllerCave() {
    return controller_cave_;
}

ControllerMaze *MainWindow::getControllerMaze(){
    return controller_maze_;
}

void MainWindow::onCaveWidthSliderValueChanged(int value) {
    ui_->cave_width_value_label->setText(QString::number(value));
}

void MainWindow::onMazeWidthSliderValueChanged(int value) {
    ui_->maze_width_value_label->setText(QString::number(value));
}

void MainWindow::onMazeHeightSliderValueChanged(int value) {
    ui_->maze_height_value_label->setText(QString::number(value));
}

void MainWindow::onCaveHeightSliderValueChanged(int value) {
    ui_->cave_height_value_label->setText(QString::number(value));
}

void MainWindow::onBirthSliderValueChanged(int value) {
    ui_->birth_value_label->setText(QString::number(value));
}

void MainWindow::onDeathSliderValueChanged(int value) {
    ui_->death_value_label->setText(QString::number(value));
}

}  // namespace s21
