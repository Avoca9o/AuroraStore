#include "helper.h"

Helper::Helper(QObject *parent) :
    QObject(parent)
{

}

Helper::~Helper() { }

void Helper::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    QString filename = path + "me/defaultuser/Pictures/Default/tiger.jpg";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << m_DownloadedData << endl;
        }
    emit downloaded();
}

void Helper::download_() {
    QUrl imageUrl("https://media.istockphoto.com/id/1347184195/photo/tiger-stands-on-a-rock-against-the-background-of-the-evening-mountain.jpg");
    connect(
        &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
        this, SLOT (fileDownloaded(QNetworkReply*))
    );


    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}

void Helper::delete_() {
    QFile::remove(path + "me/defaultuser/Pictures/Default/tiger.jpg");
}

QByteArray Helper::downloadedData() const {
    return m_DownloadedData;
}
