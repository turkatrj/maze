#include "s21_mainwindow.h"
#include "s21_graphicscene.h"
#include "forms/ui_s21_mainwindow.h"

#include <QFileDialog>

#include "../Model/s21_model_maze.h"
namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow)
{
    this->setWindowTitle("Maze");
    ui_->setupUi(this);
    setFixedSize(745, 512);
    scene_ = new s21::GraphicScene(ui_);
    ui_->graphicsView->setScene(scene_);

    connect(ui_->maze_width_slider, &QSlider::valueChanged, this,
            &MainWindow::onMazeWidthSliderValueChanged);
    connect(ui_->maze_height_slider, &QSlider::valueChanged, this,
            &MainWindow::onMazeHeightSliderValueChanged);
    connect(ui_->cave_width_slider, &QSlider::valueChanged, this,
            &MainWindow::onCaveWidthSliderValueChanged);
    connect(ui_->cave_height_slider, &QSlider::valueChanged, this,
            &MainWindow::onCaveHeightSliderValueChanged);
    connect(ui_->birth_slider, &QSlider::valueChanged, this,
            &MainWindow::onBirthSliderValueChanged);
    connect(ui_->death_slider, &QSlider::valueChanged, this,
            &MainWindow::onDeathSliderValueChanged);
    connect(ui_->load_file_maze_button, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(ui_->load_file_cave_button, SIGNAL(clicked()), this, SLOT(openFile()));
}


MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(this, "Load a file", QDir::currentPath());
    scene_->DrawFromFile(path.toStdString());
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
