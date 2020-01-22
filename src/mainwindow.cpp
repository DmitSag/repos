#include <string>
#include <fstream>

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QIcon>

#include "mainwindow.h"
#include "widget.h"

MainWindow::MainWindow()
{
    Widget *WidWin = new Widget();
    QWidget *main_window_widget = new QWidget;
    Load = new QPushButton("Load", main_window_widget);
    Save = new QPushButton("Save", main_window_widget);
    QHBoxLayout *Layout_1 = new QHBoxLayout;
    Layout_1->addWidget(Load);
    Layout_1->addWidget(Save);
    main_window_widget->setLayout(Layout_1);
    this->setCentralWidget(main_window_widget);
    Save->setEnabled(false);
    this->setWindowIcon(QIcon(":/images/icons/icon.ico"));
    this->setWindowTitle("Text Redactor");

    connect(Load, &QPushButton::clicked, WidWin, &Widget::load);
    connect(Load, &QPushButton::clicked, this, &MainWindow::savebut_invisible);
    connect(Save, &QPushButton::clicked, this, &MainWindow::save);
    connect(WidWin, &Widget::presave, this, &MainWindow::savebut_visibletrue);
    connect(WidWin, &Widget::prenotsave, this, &MainWindow::savebut_visiblefalse);
}

MainWindow::~MainWindow()
{

}

void MainWindow::save()
{
    std::string line;
    std::fstream rewrite;
    rewrite.open("rewrite.txt",  std::ios::in);
    rewrite >> line;
    rewrite.close();
    rewrite.open("test.txt", std::ios::out | std::ios::trunc);
    rewrite << line;
    rewrite.close();
}

void MainWindow::savebut_invisible()
{
    this->setVisible(false);
}

void MainWindow::savebut_visibletrue()
{
    Save->setEnabled(true);
    this->setVisible(true);
}

void MainWindow::savebut_visiblefalse()
{
    Save->setEnabled(false);
    this->setVisible(true);
}



