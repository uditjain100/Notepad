#include "mainwindow.h"
#include "iostream"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear() ;
    ui->textEdit->setText(QString()) ;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this , "Open the File") ;
    QFile file(filename) ;
    currentFile = filename ;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning" , "Cannot open file : " + file.errorString()) ;
        return ;
    }
    setWindowTitle(filename) ;
        QTextStream in(&file) ;
        QString text = in.readAll() ;
        ui->textEdit->setText(text) ;
        file.close() ;


}

void MainWindow::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as") ;
    QFile file(filename) ;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning" , "Cannot save file : " + file.errorString()) ;
        return ;
    }
    currentFile = filename ;
    setWindowTitle(filename) ;
        QString text = ui->textEdit->toPlainText() ;
        //out << text ;
        file.close() ;
}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy() ;
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste() ;
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut() ;
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo() ;
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo() ;
}
