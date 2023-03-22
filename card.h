#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <fstream>
#include <QFile>
#include <QString>
#include <QByteArray>

class Card
{
public:
    Card(QString id,QString password,double money,int level);
    QString get_pw();
    QString get_id();
    double get_money();
    int get_level();
private:
    QString user_id;
    QString user_password;
    double user_money;
    int user_level;
};

#endif // CARD_H
