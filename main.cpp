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

    QHBoxLayout *cmdLayout = new QHBoxLayout;
    cmdLayout->addWidget(openLabel);
    cmdLayout->addWidget(cmdLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout; //水平布局
    buttonLayout->addWidget(commitButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(browseButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(infoLabel);
    // mainLayout->addWidget(cmdLayout);
    // mainLayout->addWidget(buttonLayout);

    QWidget w;
    w.setLayout(mainLayout);
    // w.show();

    MainWindow window;
    window.show();
    return a.exec();
}
