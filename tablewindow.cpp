#include "tablewindow.h"
#include "ui_tablewindow.h"

TableWindow::TableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    update_table();
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->renovate_button,SIGNAL(clicked(bool)),this,SLOT(renovate_slots()));
    connect(ui->del_user_button,SIGNAL(clicked(bool)),this,SLOT(del_user_slots()));
}

TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::add_user(QString id,QString password,double money,int level){
    int cur_row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(cur_row);
    ui->tableWidget->setItem(cur_row,0,new QTableWidgetItem(id.toUtf8().data()));
    ui->tableWidget->setItem(cur_row,1,new QTableWidgetItem(password.toUtf8().data()));
    ui->tableWidget->setItem(cur_row,2,new QTableWidgetItem(QString::number(money,10,2).toUtf8().data()));
    ui->tableWidget->setItem(cur_row,3,new QTableWidgetItem(QString::number(level).toUtf8().data()));
}

void TableWindow::update_table(){
    int row_num=ui->tableWidget->rowCount();
    while(row_num--){
        ui->tableWidget->removeRow(0);
    }
    user_dir=new QDir("D:\\Qt_Work\\untitled\\user");
    user_list=new QStringList(user_dir->entryList(QDir::Files,QDir::Name));
    int n=user_list->size();
    for(int i=0;i<n;i++){
        QFile f("D:\\Qt_Work\\untitled\\user\\"+user_list->at(i));

        f.open(QIODevice::ReadOnly|QIODevice::Text);

        QByteArray r_pw_b=f.readLine();
        QString r_pw_s(r_pw_b);

        QByteArray r_money_b=f.readLine();
        QString r_money_s(r_money_b);
        double r_money=r_money_s.toDouble();

        QByteArray r_level_b=f.readLine();
        QString r_level_s(r_level_b);
        int r_level=r_level_s.toInt();

        add_user(user_list->at(i).mid(0,user_list->at(i).size()-4),r_pw_s.simplified(),r_money,r_level);
    }
}

void TableWindow::renovate_slots(){
    update_table();
}

void TableWindow::del_user_slots(){
    QString file_name=QFileDialog::getOpenFileName(this,"选择要删除的用户","D:\\Qt_Work\\untitled\\user","文本文件(*.txt)");
    QFile del_file(file_name);
    del_file.open(QIODevice::ReadOnly);
    del_file.remove();
    update_table();
}
