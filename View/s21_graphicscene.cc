#include "s21_graphicscene.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

namespace s21 {

GraphicScene::GraphicScene(QWidget *ui)
    : ui_(ui)
{
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Get Ready!");
    textItem->setDefaultTextColor(Qt::white);
    addItem(textItem);
}

GraphicScene::~GraphicScene() {}

}  // namespace s21
