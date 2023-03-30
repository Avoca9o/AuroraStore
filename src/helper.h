#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>

class Helper : public QObject
{
    Q_OBJECT

public:
    Helper();

    Q_INVOKABLE void download_();

    Q_INVOKABLE void delete_();

    virtual ~Helper() {}

private:
    QNetworkAccessManager *nam;
    const QUrl url = QUrl("https://cdn.lifehacker.ru/wp-content/uploads/2018/12/Kak-fotografirovat-kotikov-19-sovetov-ot-professionala_1544744286-640x320.jpg");
    const QString path = "home/defaultuser/Pictures/Default/";

    void onImageDownloaded_(QNetworkReply *reply);
};

#endif // HELPER_H
