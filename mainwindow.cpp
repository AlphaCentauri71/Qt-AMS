#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->background->lower();
    this->setFixedSize(800,600);
    this->setWindowTitle("海王网咖登录");
    button_clicked();
    QFile user("D:\\Qt_Work\\untitled\\user_info.txt");
    user.remove();
    this->file_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::register_slots(){
    rw=new RegisterWindow(this);
    rw->show();
}

void MainWindow::login_slots(){
    QString i_id=ui->lineEdit->text();
    QString i_password=ui->lineEdit_2->text();
    QFile login_user("D:\\Qt_Work\\untitled\\user\\"+i_id+".txt");
    login_user.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!login_user.exists()){
        QMessageBox::warning(this,"登录失败","未找到用户 "+i_id+ "，请先注册。",QMessageBox::Ok);
    }
    else{
        QByteArray r_password_b=login_user.readLine();
        QString r_password(r_password_b);
        r_password=r_password.simplified();
        if(r_password==i_password){
            QMessageBox::information(this,"登录成功","欢迎用户 "+i_id+" 使用此系统，祝您游戏愉快！",QMessageBox::Ok);
            this->close();
            mw=new MenuWindow();
            mw->get_date(i_id);
            mw->show();
        }
        else{
            QMessageBox::warning(this,"密码错误","密码错误，请检查后重新输入。",QMessageBox::Ok);

        }
    }
}

void MainWindow::button_clicked(){
    connect(ui->register_button,SIGNAL(clicked(bool)),this,SLOT(register_slots()));
    connect(ui->login_button,SIGNAL(clicked(bool)),this,SLOT(login_slots()));
}

void MainWindow::file_init(){
    user_dir=new QDir("D:\\Qt_Work\\untitled\\user");
    user_list=new QStringList(user_dir->entryList(QDir::Files,QDir::Name));
    int n=user_list->size();

    QFile user("D:\\Qt_Work\\untitled\\user_info.txt");

    for(int i=0;i<n;i++){
        QFile f("D:\\Qt_Work\\untitled\\user\\"+user_list->at(i));

        f.open(QIODevice::ReadOnly|QIODevice::Text);

        QByteArray r_id_b=user_list->at(i).mid(0,user_list->at(i).size()-4).toUtf8();
        QByteArray r_pw_b=f.readLine();
        QByteArray r_money_b=f.readLine();
        QByteArray r_level_b=f.readLine();


        f.close();

        user.open(QIODevice::Append|QIODevice::Text);

        user.write(r_id_b+'\n',r_id_b.length()+1);
        user.write(r_pw_b,r_pw_b.length());
        user.write(r_money_b,r_money_b.length());
        user.write(r_level_b,r_level_b.length());
        user.write("\n",1);

        user.close();
    }
}




