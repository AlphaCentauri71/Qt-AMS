#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <card.h>
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>
#include <tablewindow.h>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    void get_date(QString str);
    ~MenuWindow();
    void change_money(double money);
    Card *now_user;
    void change_time_money(double x){
        time_money+=x;
    }
private:
    Ui::MenuWindow *ui;
    QTimer *timer;
    double timeing;
    TableWindow *tw;
    double time_money;
    QString admin_password;
    void config();
private slots:
    void recharge();
    void play();
    void stop();
    void update_info();
    void update_money();
    void administrator();
};

#endif // MENUWINDOW_H
