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
    ApplicationListViewManager(QObject *parent = nullptr);
    virtual ~ApplicationListViewManager();
    Q_INVOKABLE void download();
    Q_INVOKABLE bool hasNext();
    Q_INVOKABLE QString getId();
    Q_INVOKABLE QString getName(QString id = "");
    Q_INVOKABLE QString getVersion(QString id = "");
    Q_INVOKABLE QString getAuthor(QString id = "");
    Q_INVOKABLE QString getLongDesctiption(QString id = "");

    Q_INVOKABLE void invoke(QString id);

private:
    struct Application {
        QString name;
        QString version;
        QString author;
        QString longDescription;
    };


    QByteArray applicationsBytes;
    QString path = "/ho";
    QVector<Application> base;
    int i;
};

#endif // APPLICATIONLISTVIEWMANAGER_H
