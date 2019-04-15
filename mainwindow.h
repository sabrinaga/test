#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void actByYourChange(QObject*);
    int getSize(QString qs);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
