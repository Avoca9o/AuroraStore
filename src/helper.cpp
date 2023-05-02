#include "helper.h"
#include <stdlib.h>

//#include "mdm-applications.h"

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
    saveToDisk(path + "me/defaultuser/myapp.rpm");
    reply->deleteLater();

//    Sailfish::Mdm::Applications *mdmApplications = new Sailfish::Mdm::Applications();
//    QObject::connect(mdmApplications->installPackage(path + "me/defaultuser/myapp.rpm"),
//                     &Sailfish::Mdm::ApplicationOperation::finished,
//                     [mdmApplications](Sailfish::Mdm::ApplicationOperation *operation) {
//        mdmApplications->deleteLater();
//    });
}

void Helper::download_() {
    QUrl url("http://5.63.153.190:8000/download/file/1");
    doDownload(url);
}

void Helper::delete_() {
    QFile::remove(path + "me/defaultuser/myapp.rpm");
}

Helper::~Helper() {
    QFile::remove(path + "me/defaultuser/data.json");
}
