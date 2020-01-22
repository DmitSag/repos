
#ifndef WIDGET_H
#define WIDGET_H

#include <string>

#include <QWidget>
#include <QTextBrowser>
#include <QMainWindow>
#include <QPushButton>

#include "mainwindow.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget();
    ~Widget();

private:
    QPushButton *delete_letters;
    QPushButton *delete_numbers;
    QPushButton *not_save;
    QPushButton *saving;
    QPushButton *delete_symbols;
    QTextBrowser *text_window;
    std::string edited_text;

public slots:
    void load();
    void save();
    void notsave();
    void deletenumbers();
    void deleteletters();
    void deletesymbols();
signals:
    void presave();
    void prenotsave();
};

#endif
