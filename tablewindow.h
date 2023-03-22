#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <card.h>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <registerwindow.h>
#include <QFileDialog>

namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();
    void add_user(QString id,QString password,double money,int level);
    Card *op_user;
    QStringList *user_list;
    void update_table();
    QDir *user_dir;
private:
    Ui::TableWindow *ui;

private slots:
    void renovate_slots();
    void del_user_slots();
};

#endif // TABLEWINDOW_H
