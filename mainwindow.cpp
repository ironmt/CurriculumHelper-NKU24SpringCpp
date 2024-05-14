#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"
#include "QMessageBox"
#include "QFontDialog"
#include "mytcp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    myserver = new MyTcp;
    connect(this, &MainWindow::sig_send_to_gpt, myserver, &MyTcp::send_to_gpt);
    connect(myserver, &MyTcp::recv_chatgpt, this, &MainWindow::update_note);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myserver;
}

//新建笔记
void MainWindow::on_new_note_triggered()
{
    // qDebug()<<"yazi";
    currentFile.clear();
    ui->textEdit->setText("");
}

//打开笔记
void MainWindow::on_open_note_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开笔记");
    QFile file(fileName);
    //如果是只读文件就报错
    if (!file.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "警告", "无法打开笔记"+file.errorString());
        return ;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_save_note_triggered()
{
    QString fileName;
    //判断是否在编辑一个已存在的笔记
    if (currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "保存笔记");
        currentFile = fileName;
    }
    else
    {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "警告", "无法保存笔记" + file.errorString());
        return ;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml();
    out<<text;
    file.close();
}

void MainWindow::on_font_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
    {
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_undo_triggered()
{
    ui->textEdit->undo();
}

//另存为
void MainWindow::on_save_as_triggered()
{
    QString fileName;
    //判断是否在编辑一个已存在的文件
    fileName = QFileDialog::getSaveFileName(this, "另存为笔记");
    currentFile = fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "警告", "无法保存笔记" + file.errorString());
        return ;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml();
    out<<text;
    file.close();
}

//加粗
void MainWindow::on_bold_triggered(bool bold)
{
    ui->textEdit->setFontWeight(bold ? QFont::Bold: QFont::Normal);
}

//斜体
void MainWindow::on_italic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}

//下划线
void MainWindow::on_underline_triggered(bool underline)
{
    ui->textEdit->setFontUnderline(underline);
}

//ai按钮
void MainWindow::on_cochatlot_triggered()
{
    QString selected_text = ui->textEdit->textCursor().selectedText();
    if (!selected_text.isEmpty())
    {
        emit sig_send_to_gpt(selected_text);
    }
    else
    {
        QMessageBox::warning(this, "警告", "没有选中任何文本");
    }
}

void MainWindow::update_note(const QString &text)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.insertText(text);
    ui->textEdit->setTextCursor(cursor);
    qDebug() << text;
 }
