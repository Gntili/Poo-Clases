#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>
#include <QPaintEvent>



#include "ventana.h"


QT_BEGIN_NAMESPACE
namespace Ui { class acceso; }
QT_END_NAMESPACE

class acceso : public QWidget
{
    Q_OBJECT

public:
    acceso(QWidget *parent = nullptr);
    ~acceso();

private:
    Ui::acceso *ui;
    Ventana *ventana;
    QImage Fondo;
    int intentosFallidos;

private slots:
    void slot_validar();
    void ImageDownload(QNetworkReply *reply);

protected:
    void paintEvent(QPaintEvent *event)override;

};
#endif // ACCESO_H
