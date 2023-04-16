#include "helper.h"
#include <stdlib.h>

Helper::Helper(QObject *parent) :
    QObject(parent)
{

}

Helper::~Helper() { }

void Helper::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    QString filename = path + "me/defaultuser/myapp.rpm";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << m_DownloadedData << endl;
    }
    Sailfish::Mdm::Applications *mdmApplications = new Sailfish::Mdm::Applications();
    QObject::connect(mdmApplications->installPackage(path + "me/defaultuser/myapp.rpm"),
                     &Sailfish::Mdm::ApplicationOperation::finished,
                     [mdmApplications](Sailfish::Mdm::ApplicationOperation *operation) {
        mdmApplications->deleteLater();
        if (operation->isSucceeded()) {
            std::cout << " installed\n";
        } else {
            std::cout << " not installed\n";
        }
    });
    emit downloaded();
}

void Helper::download_() {
    QUrl imageUrl("https://disk.yandex.ru/d/8VEsc3HCd1ikyg");
    connect(
        &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (fileDownloaded(QNetworkReply*))
    );


    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}

void Helper::delete_() {
    QFile::remove(path + "me/defaultuser/myapp.rpm");
}

QByteArray Helper::downloadedData() const {

    return m_DownloadedData;
}
