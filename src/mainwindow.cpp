#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->todoList->setModel(new QStringListModel());
    ui->wipList->setModel(new QStringListModel());
    ui->doneList->setModel(new QStringListModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addAction_triggered()
{
    
}


void MainWindow::on_editAction_triggered()
{
    
}


void MainWindow::on_removeAction_triggered()
{
    
}


void MainWindow::on_saveAsAction_triggered()
{
    
}


void MainWindow::on_saveAction_triggered()
{
    
}


void MainWindow::on_closeAction_triggered()
{
    
}


void MainWindow::on_openAction_triggered()
{
    
}


void MainWindow::on_quitAction_triggered()
{
    
}


void MainWindow::on_aboutAction_triggered()
{
    QMessageBox::about(
        this, "Про TaskList Demo " + appVersion,
        "Настільний застосунок управляння завданнями, виконаний\n"
        "для лаби 1 з дисципліни «Основи DevOps інженерії».\n\n"
        "© 2026 Михайло Стецюк\n"
        "Надається під MIT License"
        );
}


void MainWindow::on_aboutQtAction_triggered()
{
    QMessageBox::aboutQt(this, "Про Qt Framework");
}