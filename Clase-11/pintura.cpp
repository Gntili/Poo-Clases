#include "pintura.h"
#include <QMouseEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), currentColor(Qt::black), brushSize(5)
{
    setWindowTitle("Pintura");
    setAttribute(Qt::WA_StaticContents);
}

Pintura::~Pintura() {}

void Pintura::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        points.append(event->pos());
        update();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && !points.isEmpty()) {
        points.append(event->pos());
        update();
    }
}

void Pintura::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(currentColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    for (int i = 1; i < points.size(); ++i) {
        painter.drawLine(points[i - 1], points[i]);
    }
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
        brushSize++;
    } else if (event->delta() < 0 && brushSize > 1) {
        brushSize--;
    }
}

void Pintura::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_R:
        currentColor = Qt::red;
        break;
    case Qt::Key_G:
        currentColor = Qt::green;
        break;
    case Qt::Key_B:
        currentColor = Qt::blue;
        break;
    case Qt::Key_Escape:
        points.clear();
        update();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
