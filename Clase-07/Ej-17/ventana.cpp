// ventana.cpp
#include "ventana.h"
#include "ui_ventana.h"
#include <QVBoxLayout>
#include <QDebug>


Ventana::Ventana(const QString &usuario, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);

    qDebug()<<usuario;

    if (usuario == "Admin") {
        label->setText("Hola Admin");
    } else {
        label->setText("Hola User");
    }

    layout->addWidget(label);

    QNetworkAccessManager *Manager = new QNetworkAccessManager(this);
    connect(Manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(ImageDownload(QNetworkReply*)));
    Manager->get(QNetworkRequest(QUrl("https://img.freepik.com/vector-gratis/hermoso-personaje-pajaro-fuego-fenix-plumas-naranjas-ardientes-ilustracion-dibujos-animados-vectoriales-pajaro-magico-mitologia-fenix-cuento-hadas-fuego-aislado-sobre-fondo-blanco_107791-11544.jpg?w=740&t=st=1718220570~exp=1718221170~hmac=f56accbe9a7c73a20e46df9f67f77ea5c2e65af512c95428da2ea058ca0d72c5")));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::ImageDownload(QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError){
        QByteArray imageData= reply->readAll();
        Fondo.loadFromData(imageData);
        update();
    }
    else{
        qDebug()<<"No se pudo descargar";
    }
    reply->deleteLater();
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter Painter(this);

    if(!Fondo.isNull()){
        Painter.drawImage(0,0,Fondo.scaled(this->size()));
    }
}

