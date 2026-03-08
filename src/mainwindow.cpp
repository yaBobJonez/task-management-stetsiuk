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
    auto list = qobject_cast<QListView*>(QApplication::focusWidget());
    if (list == nullptr) return;
    auto model = list->model();
    model->insertRow(model->rowCount());
    auto index = model->index(model->rowCount() - 1, 0);
    list->setCurrentIndex(index);
    list->edit(index);
}


void MainWindow::on_editAction_triggered()
{
    auto list = qobject_cast<QListView*>(QApplication::focusWidget());
    if (list == nullptr) return;
    list->edit(list->currentIndex());
}


void MainWindow::on_removeAction_triggered()
{
    auto list = qobject_cast<QListView*>(QApplication::focusWidget());
    if (list == nullptr) return;
    list->model()->removeRow(list->currentIndex().row());
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
    QMessageBox::StandardButton res = QMessageBox::question(
        this, "Вихід з програми",
        "Чи хочете Ви зберегти дошку перед виходом?",
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
        QMessageBox::Save
        );
    if (res == QMessageBox::Cancel) return;
    if (res == QMessageBox::Save) ui->saveAction->trigger();
    QApplication::quit();
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