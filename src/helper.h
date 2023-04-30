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

//#include "mdm-applications.h"

class Helper : public QObject
{
    Q_OBJECT
    QNetworkAccessManager manager;
    QNetworkAccessManager AppListManager;
    QNetworkReply *currentDownload;
    const QString path = "/ho";
public:
    Helper();
    virtual ~Helper();
    void doDownload(const QUrl& url);
    bool saveToDisk(const QString& data);
    Q_INVOKABLE void download_();
    Q_INVOKABLE void delete_();

public slots:
    void downloadFinished(QNetworkReply *reply);
    void downloadApplicationListFinished(QNetworkReply *replyAL);
};

#endif // HELPER_H
