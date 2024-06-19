#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Qlabel");
    QWidget widget;
    QPushButton button("Boton");
    QLineEdit lineEdit;

    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
