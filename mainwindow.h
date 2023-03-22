#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTabWidget>
#include <QPainter>
#include <QPixmap>
#include <QPalette>
#include <QImage>
#include <QLabel>
#include <QVBoxLayout>
#include <card.h>
#include <registerwindow.h>
#include <QString>
#include <menuwindow.h>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void button_clicked();
    QStringList *user_list;
    QDir *user_dir;
private slots:
    void register_slots();
    void login_slots();
private:
    Ui::MainWindow *ui;
    RegisterWindow *rw;
    MenuWindow *mw;
    void file_init();
};


#endif // MAINWINDOW_H
