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
    qDebug() << "Added new task.";
}


void MainWindow::on_editAction_triggered()
{
    auto list = qobject_cast<QListView*>(QApplication::focusWidget());
    if (list == nullptr) return;
    list->edit(list->currentIndex());
    qDebug() << "Editing task.";
}


void MainWindow::on_removeAction_triggered()
{
    auto list = qobject_cast<QListView*>(QApplication::focusWidget());
    if (list == nullptr) return;
    list->model()->removeRow(list->currentIndex().row());
    qDebug() << "Removed task.";
}


void MainWindow::on_saveAsAction_triggered()
{
    saveFile = QFileDialog::getSaveFileName(this, "Зберегти дошку", {}, "CSV (*.csv)");
    if (saveFile.isEmpty()) return;
    ui->saveAction->trigger();
}


void MainWindow::on_saveAction_triggered()
{
    if (saveFile.isEmpty()) {
        ui->saveAsAction->trigger();
        return;
    }
    QFile f(saveFile);
    if (!f.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Помилка збереження", "Не вдалося відкрити файл на запис.");
        return;
    }
    QTextStream os(&f);
    os << qobject_cast<QStringListModel*>(ui->todoList->model())->stringList().join(",") << "\n";
    os << qobject_cast<QStringListModel*>(ui->wipList->model())->stringList().join(",") << "\n";
    os << qobject_cast<QStringListModel*>(ui->doneList->model())->stringList().join(",") << "\n";
}


void MainWindow::on_closeAction_triggered()
{
    saveFile.truncate(0);
}


void MainWindow::on_openAction_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Відкрити дошку", {}, "CSV (*.csv)");
    if (filename.isEmpty()) return;
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "Помилка відкриття", "Не вдалося прочитати вказаний файл.");
        return;
    }
    saveFile = filename;
    QTextStream is(&f);
    ui->todoList->setModel(new QStringListModel( is.readLine().split(",", Qt::SkipEmptyParts) ));
    ui->wipList->setModel(new QStringListModel( is.readLine().split(",", Qt::SkipEmptyParts) ));
    ui->doneList->setModel(new QStringListModel( is.readLine().split(",", Qt::SkipEmptyParts) ));
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
