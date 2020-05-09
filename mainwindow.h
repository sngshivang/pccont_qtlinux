#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString pref;
    QString un;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onFiniish(QNetworkReply *);
    void netcon(QString, QString);
    void loginretcall(QString);
    void clavail(QString);
    //void onFinish (QNetworkReply *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
