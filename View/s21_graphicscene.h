#ifndef SRC_VIEW_GRAPHICSCENE_H
#define SRC_VIEW_GRAPHICSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace s21 {

class GraphicScene : public QGraphicsScene
{
public:
    explicit GraphicScene(QWidget *ui);
    ~GraphicScene();

private:
    QWidget *ui_;

};

}  // namespace s21

#endif // SRC_VIEW_GRAPHICSCENE_H
