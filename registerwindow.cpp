#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->background->lower();
    connect(ui->register_button,SIGNAL(clicked(bool)),this,SLOT(register_new()));
    connect(ui->return_button,SIGNAL(clicked(bool)),this,SLOT(close()));
    this->setFixedSize(800,600);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::register_new(){
    QString id=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QFile register_user("D:\\Qt_Work\\untitled\\user\\"+id+".txt");
    if(register_user.exists()){
        QMessageBox::warning(this,"注册失败","用户名 " +id+" 被占用，请更换用户名后重新注册。",QMessageBox::Ok);
    }
    else{
        if(ui->lineEdit_2->text()!=ui->lineEdit_3->text()){
            QMessageBox::warning(this,"错误","两次输入密码不一致，请检查后重新输入！",QMessageBox::Ok);
        }
        else{

            Card new_card(id,password,10,0);
            QString strinfo="账号 "+id+" 已经注册成功,请返回登录界面。";
            QMessageBox::information(this,"注册成功",strinfo,QMessageBox::Ok);
            this->close();
        }
    }
}
