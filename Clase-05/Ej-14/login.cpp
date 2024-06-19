#include "login.h"
#include <QGridLayout>
#include <QPainter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent) {
    setMaximumSize(750, 500);
    setMinimumSize(250, 250);

    lUsuario = new QLabel("Usuario:");
    leUsuario = new QLineEdit;
    lClave = new QLabel("Clave:");
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbValidar = new QPushButton("Validar");
    pbAlternarTemperatura = new QPushButton("Mostrar u ocultar Temperatura");
    lClima = new QLabel("");

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 1, 1, 2);
    layout->addWidget(pbAlternarTemperatura, 3, 0, 1, 2);
    layout->addWidget(lClima, 4, 0, 1, 2);

    connect(pbValidar, SIGNAL(pressed()), this, SLOT(slot_ValidarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_ValidarUsuario()));
    connect(pbAlternarTemperatura, SIGNAL(pressed()), this, SLOT(slot_alternarTemperatura()));

    manager = new QNetworkAccessManager(this);
    managerClima = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargafinalizada(QNetworkReply*)));
    connect(managerClima, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargafinalizadaClima(QNetworkReply*)));

    QNetworkRequest requestClima(QUrl("https://api.weatherapi.com/v1/current.json?key=6ebf146961d24c06b6a02801241104&q=Cordoba&aqi=no"));
    managerClima->get(requestClima);

    QNetworkRequest request(QUrl("https://t3.ftcdn.net/jpg/06/59/38/36/360_F_659383648_VZeGUlpn5q2NVMgxdcYU6rMGXBtlhsh3.jpg"));
    manager->get(request);

    adminDB = new AdminDB(this);
    adminDB->openDB("C:/Users/Santiago/Desktop/Poo - Ejercicios 14-16/Ej-14/db.sqlite");
}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
}

void Login::slot_descargafinalizadaClima(QNetworkReply *reply) {
    QByteArray jsonDevuelto = reply->readAll();
    qDebug() << jsonDevuelto;

    QJsonDocument doc = QJsonDocument::fromJson(jsonDevuelto);
    if (doc.isObject()) {
        QJsonObject currentObject = doc.object()["current"].toObject();
        if (currentObject.contains("temp_c")) {
            double temperatureC = currentObject["temp_c"].toDouble();
            qDebug() << "Temperatura (Celsius):" << temperatureC;
            lClima->setText(QString("%1°C").arg(temperatureC));
            lClima->setVisible(true);
        } else {
            qDebug() << "Error: 'temp_c' key not found in 'current' object";
        }
    } else {
        qDebug() << "Error: Invalid JSON format";
    }
}

void Login::mostrarTemperatura(bool mostrar) {
    lClima->setVisible(mostrar);
}

void Login::slot_alternarTemperatura() {
    mostrarTemperatura(!lClima->isVisible());
}

void Login::slot_descargafinalizada(QNetworkReply *reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::slot_ValidarUsuario() {
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    QStringList datos = adminDB->validateUser(usuario, clave);
    if (!datos.isEmpty()) {
        emit usuarioValido();
    } else {
        qDebug() << "Usuario no válido";
    }
}
