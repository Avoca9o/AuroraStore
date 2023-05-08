#include "helper.h"
#include <stdlib.h>

Helper::Helper()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
    connect(&AppListManager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadApplicationListFinished(QNetworkReply*)));
    QUrl url("http://5.63.153.190:8000/");
    QNetworkRequest request(url);
    currentDownload = AppListManager.get(request);
}

void Helper::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    currentDownload = reply;
}

bool Helper::saveToDisk(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(currentDownload->readAll());
    file.close();

    return true;
}

void Helper::downloadApplicationListFinished(QNetworkReply *replyAL) {
    QFile file(path + "me/defaultuser/applications.json");
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Could not open %s for saving applications json: %s\n",
                qPrintable(("applications.json")),
                qPrintable(file.errorString()));
        return;
    }
    file.write(currentDownload->readAll());
    file.close();
}

void Helper::downloadFinished(QNetworkReply *reply)
{
    saveToDisk(path + "me/defaultuser/" + currentId + ".rpm");
    reply->deleteLater();
}

void Helper::download_(QString id) {
    QUrl url("http://5.63.153.190:8000/download/file/" + id);
    currentId = id;
    doDownload(url);
}

void Helper::delete_() {
    QFile::remove(path + "me/defaultuser/myapp.rpm");
}

bool Helper::checkInternetConnection_() {
    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost("www.google.com", 80);
    bool connected = socket->waitForConnected(30000);

    if (!connected) {
        socket->abort();
        return false;
    }
    socket->close();
    return true;
}

void Helper::quit_() {
    exit(0);
}

Helper::~Helper() {
    QFile::remove(path + "me/defaultuser/applications.json");
}
