#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QByteArray>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <iostream>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = 0);
    virtual ~Helper();
    QByteArray downloadedData() const;
    Q_INVOKABLE void download_();
    Q_INVOKABLE void delete_();

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);
    private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
    const QString path = "/ho";
};

#endif // HELPER_H
