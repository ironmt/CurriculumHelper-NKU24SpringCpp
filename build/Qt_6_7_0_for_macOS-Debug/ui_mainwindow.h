/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_note;
    QAction *open_note;
    QAction *save_note;
    QAction *font;
    QAction *undo;
    QAction *save_as;
    QAction *bold;
    QAction *italic;
    QAction *underline;
    QAction *cochatlot;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        new_note = new QAction(MainWindow);
        new_note->setObjectName("new_note");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ img/img/create.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("images/create.png"), QSize(), QIcon::Normal, QIcon::On);
        new_note->setIcon(icon);
        new_note->setMenuRole(QAction::NoRole);
        open_note = new QAction(MainWindow);
        open_note->setObjectName("open_note");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ img/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_note->setIcon(icon1);
        open_note->setMenuRole(QAction::NoRole);
        save_note = new QAction(MainWindow);
        save_note->setObjectName("save_note");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_note->setIcon(icon2);
        save_note->setMenuRole(QAction::NoRole);
        font = new QAction(MainWindow);
        font->setObjectName("font");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ img/img/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        font->setIcon(icon3);
        font->setMenuRole(QAction::NoRole);
        undo = new QAction(MainWindow);
        undo->setObjectName("undo");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ img/img/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon4);
        undo->setMenuRole(QAction::NoRole);
        save_as = new QAction(MainWindow);
        save_as->setObjectName("save_as");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ img/img/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_as->setIcon(icon5);
        save_as->setMenuRole(QAction::NoRole);
        bold = new QAction(MainWindow);
        bold->setObjectName("bold");
        bold->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ img/img/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        bold->setIcon(icon6);
        bold->setMenuRole(QAction::NoRole);
        italic = new QAction(MainWindow);
        italic->setObjectName("italic");
        italic->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ img/img/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italic->setIcon(icon7);
        italic->setMenuRole(QAction::NoRole);
        underline = new QAction(MainWindow);
        underline->setObjectName("underline");
        underline->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ img/img/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        underline->setIcon(icon8);
        underline->setMenuRole(QAction::NoRole);
        cochatlot = new QAction(MainWindow);
        cochatlot->setObjectName("cochatlot");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/gpt/gpt/ChatGPT_logo.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        cochatlot->setIcon(icon9);
        cochatlot->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(130, 10, 461, 351));
        QFont font1;
        font1.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        textEdit->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(new_note);
        menu->addAction(open_note);
        menu->addSeparator();
        menu->addAction(save_note);
        menu->addAction(save_as);
        menu_2->addAction(bold);
        menu_2->addAction(italic);
        menu_2->addAction(underline);
        menu_2->addSeparator();
        menu_2->addAction(undo);
        toolBar->addAction(new_note);
        toolBar->addAction(open_note);
        toolBar->addAction(save_note);
        toolBar->addAction(save_as);
        toolBar->addSeparator();
        toolBar->addAction(cochatlot);
        toolBar->addSeparator();
        toolBar->addAction(font);
        toolBar->addAction(undo);
        toolBar->addSeparator();
        toolBar->addAction(bold);
        toolBar->addAction(italic);
        toolBar->addAction(underline);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CurriculumHelper", nullptr));
        new_note->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\347\254\224\350\256\260", nullptr));
#if QT_CONFIG(shortcut)
        new_note->setShortcut(QCoreApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        open_note->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\347\254\224\350\256\260", nullptr));
#if QT_CONFIG(shortcut)
        open_note->setShortcut(QCoreApplication::translate("MainWindow", "Meta+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save_note->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\347\254\224\350\256\260", nullptr));
#if QT_CONFIG(shortcut)
        save_note->setShortcut(QCoreApplication::translate("MainWindow", "Meta+S", nullptr));
#endif // QT_CONFIG(shortcut)
        font->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        font->setShortcut(QCoreApplication::translate("MainWindow", "Meta+F", nullptr));
#endif // QT_CONFIG(shortcut)
        undo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\345\233\236", nullptr));
#if QT_CONFIG(shortcut)
        undo->setShortcut(QCoreApplication::translate("MainWindow", "Meta+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        save_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        bold->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
        italic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
        underline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
        cochatlot->setText(QCoreApplication::translate("MainWindow", "CoChatlot", nullptr));
#if QT_CONFIG(shortcut)
        cochatlot->setShortcut(QCoreApplication::translate("MainWindow", "Meta+I", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
