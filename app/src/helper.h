#ifndef HELPER_H
#define HELPER_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>

#include <stdio.h>

class Helper : public QObject
{
    Q_OBJECT
    QNetworkAccessManager manager;
    QNetworkAccessManager AppListManager;
    QNetworkReply *currentDownload;
    const QString path = "/ho";
    QString currentId;
public:
    Helper();
    virtual ~Helper();
    void doDownload(const QUrl& url);
    bool saveToDisk(const QString& data);
    Q_INVOKABLE bool checkInternetConnection_();
    Q_INVOKABLE void download_();
    Q_INVOKABLE void delete_();
    Q_INVOKABLE void quit_();
    Q_INVOKABLE void setCurrentId(QString id);
    Q_INVOKABLE QString getCurrentId();

public slots:
    void downloadFinished(QNetworkReply *reply);
    void downloadApplicationListFinished(QNetworkReply *replyAL);
};

#endif // HELPER_H
