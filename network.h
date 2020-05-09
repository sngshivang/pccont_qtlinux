#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QHttpPart>
#include <QNetworkReply>
#include <QObject>
#include <mainwindow.h>
#include <QUrlQuery>

  void MainWindow::netcon(QString opt, QString qry)
    {
        MainWindow::pref = opt;
        QNetworkAccessManager *test = new QNetworkAccessManager(this);
      QUrl url("https://qfrat.co.in/pc_cont/operator.php");
      QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        //QUrlQuery params;
        //params.addQueryItem("typ", "4");
        bool trip = connect(test, SIGNAL(finished(QNetworkReply *)), this, SLOT(onFiniish(QNetworkReply *)));
        //qDebug(QString::number(trip).toLatin1());
        //test->post(request, params.query().toUtf8());
        test->post(request, qry.toUtf8());
    }
    void MainWindow::onFiniish(QNetworkReply *rep)
     {
         QByteArray bts = rep->readAll();
         QString str(bts);
         qDebug(str.toLatin1());
         if (MainWindow::pref == "4")
         {
             loginretcall(str);
         }
         else if (MainWindow::pref == "2")
         {
             clavail(str);
         }
     }

