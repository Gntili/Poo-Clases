#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QColor>
#include <QPoint>

class Pintura : public QWidget
{
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);
    ~Pintura();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QColor currentColor;
    int brushSize;
    QVector<QPoint> points;
};

#endif // PINTURA_H
