#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QString currentFile;
};
#endif // MAINWINDOW_H

