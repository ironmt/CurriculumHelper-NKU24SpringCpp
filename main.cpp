#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();
    return a.exec();
}
