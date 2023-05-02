#ifndef APPLICATIONLISTVIEWMANAGER_H
#define APPLICATIONLISTVIEWMANAGER_H

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

class ApplicationListViewManager : public QObject
{
    Q_OBJECT
public:
    ApplicationListViewManager();
    virtual ~ApplicationListViewManager();
    Q_INVOKABLE void download();
    Q_INVOKABLE bool hasNext();
    Q_INVOKABLE QString getId();
    Q_INVOKABLE QString getName();
    Q_INVOKABLE QString getVersion();
    Q_INVOKABLE QString getAuthor();

    Q_INVOKABLE void invoke(QString id);

private:
    struct Application {
        QString name;
        QString version;
        QString author;
    };


    QByteArray applicationsBytes;
    QString path = "/ho";
    QVector<Application> base;
    int i;
};

#endif // APPLICATIONLISTVIEWMANAGER_H
