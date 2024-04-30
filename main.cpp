#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel *infoLabel = new QLabel;
    QLabel *openLabel = new QLabel;
    QLineEdit *cmdLineEdit = new QLineEdit;
    QPushButton *commitButton = new QPushButton;
    QPushButton *cancelButton = new QPushButton;
    QPushButton *browseButton = new QPushButton;

    infoLabel->setText("命令行");
    openLabel->setText("打开");
    commitButton->setText("确认");
    cancelButton->setText("取消");
    browseButton->setText("鸭鸭");
    return a.exec();
}
