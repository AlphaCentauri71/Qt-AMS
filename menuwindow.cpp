#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    time_money(1),
    admin_password("12345"),
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    ui->background->lower();
    this->setFixedSize(800,600);
    this->setWindowTitle("海王网咖");
    this->config();
    timeing=0;
    connect(ui->actionrecharge,SIGNAL(triggered(bool)),this,SLOT(recharge()));
    connect(ui->actionplay,SIGNAL(triggered(bool)),this,SLOT(play()));
    connect(ui->actionstop,SIGNAL(triggered(bool)),this,SLOT(stop()));
    connect(ui->actionadministrator,SIGNAL(triggered(bool)),this,SLOT(administrator()));
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::get_date(QString str){
    QFile login_user("D:\\Qt_Work\\untitled\\user\\"+str+".txt");
    login_user.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray r_pw_b=login_user.readLine();
    QString r_pw_s(r_pw_b);

    QByteArray r_money_b=login_user.readLine();
    QString r_money_s(r_money_b);
    double r_money=r_money_s.toDouble();

    QByteArray r_level_b=login_user.readLine();
    QString r_level_s(r_level_b);
    int r_level=r_level_s.toInt();

    login_user.close();

    now_user=new Card(str,r_pw_s,r_money,r_level);
    update_info();
}

void MenuWindow::recharge(){

    double re_money=QInputDialog::getDouble(this,"充值","请输入您要充值的金额",0,0,10000,2);
    if(re_money!=0){
        QMessageBox::information(this,"充值确认","您即将充值 "+QString::number(re_money)+" 元，是否确认？",QMessageBox::Yes|QMessageBox::No);
        change_money(re_money);
    }
}

void MenuWindow::change_money(double money){
    QString id=this->now_user->get_id();
    QFile login_user("D:\\Qt_Work\\untitled\\user\\"+id+".txt");
    login_user.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray r_pw_b=login_user.readLine();
    QString r_pw_s(r_pw_b);

    QByteArray r_money_b=login_user.readLine();
    QString r_money_s(r_money_b);
    double r_money=r_money_s.toDouble();

    QByteArray r_level_b=login_user.readLine();
    QString r_level_s(r_level_b);
    int r_level=r_level_s.toInt();

    r_money+=money;

    login_user.close();

    now_user=new Card(id,r_pw_s,r_money,r_level);
    update_info();

}

void MenuWindow::update_info(){

    QString id=now_user->get_id();
    QString money=QString::number(now_user->get_money(),10,2);
    QString level=QString::number(now_user->get_level());
    ui->label_time->setText(QString::number(timeing,10,2).simplified()+" s");
    ui->label_id->setText(id.simplified());
    ui->label_money->setText(money.simplified()+" 元");
    ui->label_level->setText(level.simplified());

}

void MenuWindow::play(){
    QMessageBox::StandardButton rb=QMessageBox::information(this,"开始游戏","您即将进行游戏，是否确定？",QMessageBox::Yes|QMessageBox::No);
    if(rb==QMessageBox::Yes){
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(update_money()));
        timer->start(2000);
    }
}

void MenuWindow::update_money(){
    timeing+=1;
    change_money(-1*time_money);
}

void MenuWindow::stop(){
    QMessageBox::information(this,"暂停","您暂停了游戏。",QMessageBox::Yes);
    timer->stop();
}

void MenuWindow::administrator(){
    QString input_password=QInputDialog::getText(this,"管理员模式","请输入管理员密码",QLineEdit::Password);
    if(input_password==admin_password){
        tw=new TableWindow(this);
        tw->show();
    }
    else{
        QMessageBox::information(this,"密码错误","密码错误，请检查后重新输入！");
    }
}

void MenuWindow::config(){
    QFile config_file("D:\\Qt_Work\\untitled\\config.txt");
    config_file.open(QIODevice::WriteOnly|QIODevice::Text);
    admin_password=admin_password.simplified();

    QByteArray admin_passwordBytes=admin_password.toUtf8();
    config_file.write(admin_passwordBytes+"\n",admin_passwordBytes.length()+1);
}
