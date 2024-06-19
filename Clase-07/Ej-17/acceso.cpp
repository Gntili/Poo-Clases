#include "acceso.h"
#include "ui_acceso.h"


#include <QDebug>

acceso::acceso(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::acceso)
    ,intentosFallidos(0)
{
    ui->setupUi(this);

    // SLOTS
    connect(ui->pningresar,SIGNAL(clicked(bool)),this,SLOT(slot_validar()));
    connect(ui->leClave, SIGNAL(returnPressed()),SLOT(slot_validar()));

    //DESCARGAR IMAGEN DESDE URL
    QNetworkAccessManager *Manager = new QNetworkAccessManager(this);
    connect(Manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(ImageDownload(QNetworkReply*)));
    Manager->get(QNetworkRequest(QUrl("https://img.freepik.com/foto-gratis/fondo-degradado-futurista-lineas-particulas-blancas_53876-102621.jpg")));
}

acceso::~acceso()
{
    delete ui;
}

void acceso::slot_validar()
{
    if((ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234") || (ui->leUsuario->text() ==  "user"  && ui->leClave->text() == "4321")){
        qDebug()<<"Usuario admin valido";
        this->hide();
        if(ui->leUsuario->text()=="admin"){
            qDebug()<<"entre";
            ventana = new Ventana("Admin");
            ventana->show();
        }
        else{
            ventana = new Ventana("User");
            ventana->show();
        }
    }
    else{
        qDebug()<<"Usuario inexistente";
        intentosFallidos++;
        if(intentosFallidos>=3){
            qApp->quit();
        }

    }
}

void acceso::ImageDownload(QNetworkReply *reply)
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

void acceso::paintEvent(QPaintEvent *)
{
    QPainter Painter(this);

    if(!Fondo.isNull()){
        Painter.drawImage(0,0,Fondo.scaled(this->size()));

    }
}

