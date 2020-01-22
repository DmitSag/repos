#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>

#include <QMainWindow>
#include <QPushButton>

#include "widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

private:
    QPushButton *Load;
    QPushButton *Save;

private slots:
    void save();
    void savebut_invisible();
    void savebut_visibletrue();
    void savebut_visiblefalse();
};

#endif
