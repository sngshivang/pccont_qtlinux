#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QMessageBox>
#include <QtNetwork/QNetworkReply>
#include <network.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainwidget->setVisible(false);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->statlabel->setText("CONNECTING TO SERVER...");
    QString usr = ui->usrnme->text();
    QString pwd = ui->usrpwd->text();
    MainWindow::un = usr;
    qDebug(usr.toLatin1());
    QString out = "typ=4&nm="+usr+"&pw="+pwd;
    netcon("4", out);

}
void MainWindow::loginretcall(QString resp)
{
    if (resp == "1"){
    ui->statlabel->setText("LOGIN SUCCESSFUL. VERIFYING HOST LOGIN...");
    QString send = "typ=2&nm="+MainWindow::un;
    netcon("2",send);
    }
    else {
        MainWindow::un = nullptr;
        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "Save", "Failed to login ",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            qDebug() << "Yes was clicked";
            // code for saving...
        }
        if (reply == QMessageBox::Discard)
        {
            // toDo
        }
        if(reply == QMessageBox::Cancel)
        {
            //toDo
        }
    }


}
void MainWindow::clavail(QString inp)
{
    if (inp !="0")
    {
        ui->statlabel->setText("HOST IS LOGGED IN");
    }
}

/*void MainWindow::onFinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    qDebug(str.toLatin1());
}*/


