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
    void on_addAction_triggered();

    void on_editAction_triggered();

    void on_removeAction_triggered();

    void on_saveAsAction_triggered();

    void on_saveAction_triggered();

    void on_closeAction_triggered();

    void on_openAction_triggered();

    void on_quitAction_triggered();

    void on_aboutAction_triggered();

    void on_aboutQtAction_triggered();

private:
    Ui::MainWindow *ui;
    QString appVersion = "1.0.0";

    QString saveFile;
};
#endif // MAINWINDOW_H