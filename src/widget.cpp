#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QString>

#include <fstream>
#include <ctype.h>

#include "widget.h"
#include "mainwindow.h"

Widget::Widget()
{
    saving = new QPushButton("Save");
    not_save = new QPushButton("Not Save");
    delete_numbers = new QPushButton("Delete numbers");
    delete_letters = new QPushButton("Delete letters");
    delete_symbols = new QPushButton("Delete symbols");
    QHBoxLayout *Layout_2 = new QHBoxLayout;
    text_window = new QTextBrowser;
    Layout_2->addWidget(saving);
    Layout_2->addWidget(not_save);
    Layout_2->addWidget(delete_numbers);
    Layout_2->addWidget(delete_letters);
    Layout_2->addWidget(delete_symbols);
    QVBoxLayout *Layout_3 = new QVBoxLayout;
    Layout_3->addWidget(text_window);
    Layout_3->addLayout(Layout_2);
    this->setLayout(Layout_3);

    this->setWindowIcon(QIcon(":/images/icons/icon.ico"));
    this->setWindowTitle("Text Redactor");

    connect(saving, &QPushButton::clicked, this, &Widget::save);
    connect(not_save, &QPushButton::clicked, this, &Widget::notsave);
    connect(delete_numbers, &QPushButton::clicked, this, &Widget::deletenumbers);
    connect(delete_letters, &QPushButton::clicked, this, &Widget::deleteletters);
    connect(delete_symbols, &QPushButton::clicked, this, &Widget::deletesymbols);
}

Widget::~Widget()
{

}

void Widget::load()
{
    std::fstream in;
    in.open("test.txt",  std::ios::in);
    std::string buf;
    edited_text.clear();
    while(!in.eof())
    {
        buf.clear();
        in >> buf;
        edited_text += buf;
    }
    QString str = QString::fromStdString(edited_text);
    text_window->setText(str);
    this->show();
    in.close();
}

void Widget::save()
{
    std::fstream out;
    out.open("rewrite.txt", std::ios::out | std::ios::trunc );
    out << edited_text;
    out.close();
    emit presave();
    this->close();
}

void Widget::notsave()
{
    this->close();
    emit prenotsave();
}

void Widget::deletenumbers()
{
    std::string buf;
    for(unsigned int i = 0; i < edited_text.length(); i++)
    {
        if(!isdigit(edited_text[i]))
        {
            buf = buf + edited_text[i];
        }
    }
    edited_text = buf;
    QString str = QString::fromStdString(buf);
    text_window->setText(str);
}

void Widget::deleteletters()
{
    std::string buf;
    for(unsigned int i = 0; i < edited_text.length();i++)
    {
        if(!isalpha(edited_text[i]))
        {
            buf = buf + edited_text[i];
        }
    }
    edited_text = buf;
    QString str = QString::fromStdString(buf);
    text_window->setText(str);
}

void Widget::deletesymbols()
{
    std::string buf;
    for(unsigned int i = 0; i < edited_text.length(); i++)
    {
        if((isdigit(edited_text[i]))||(isalpha(edited_text[i])))
        {
            buf = buf + edited_text[i];
        }
    }
    edited_text = buf;
    QString str = QString::fromStdString(buf);
    text_window->setText(str);
}
