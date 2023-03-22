#include "card.h"

Card::Card(QString id,QString password,double money,int level ):user_id(id),user_password(password),user_money(money),user_level(level)
{
    QFile card_info("D:\\Qt_Work\\untitled\\user\\"+id+".txt");

    card_info.open(QIODevice::WriteOnly|QIODevice::Text);

    password=password.simplified();

    QByteArray passwordBytes=password.toUtf8();
    card_info.write(passwordBytes+"\n",passwordBytes.length()+1);

    QString money_str=QString::number(money,10,2);
    QByteArray moneyBytes=money_str.toUtf8();
    card_info.write(moneyBytes+"\n",moneyBytes.length()+1);

    QString level_str=QString::number(level);
    QByteArray levelBytes=level_str.toUtf8();
    card_info.write(levelBytes+"\n",levelBytes.length()+1);
    card_info.close();
}

QString Card::get_id(){
    return this->user_id;
}

QString Card::get_pw(){
    return this->user_password;
}

double Card::get_money(){
    return this->user_money;
}

int Card::get_level(){
    return this->user_level;
}
