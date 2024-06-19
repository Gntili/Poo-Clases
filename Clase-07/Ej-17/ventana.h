#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(const QString &usuario,QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QLabel *label;
     QImage Fondo;

private slots:
     void ImageDownload(QNetworkReply *reply);

protected:
    void paintEvent(QPaintEvent *event)override;
};

#endif // VENTANA_H
