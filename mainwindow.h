#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytcp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_new_note_triggered();

    void on_open_note_triggered();

    void on_save_note_triggered();

    void on_font_triggered();

    void on_undo_triggered();

    void on_save_as_triggered();

    void on_bold_triggered(bool checked);

    void on_italic_triggered(bool checked);

    void on_underline_triggered(bool checked);

    void on_cochatlot_triggered();

signals:
    void sig_send_to_gpt(const QString &text);

public slots:
    void update_note(const QString &text);

private:
    Ui::MainWindow *ui;
    QString currentFile;
    MyTcp *myserver;
};
#endif // MAINWINDOW_H

