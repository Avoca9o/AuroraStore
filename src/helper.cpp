#include "helper.h"
#include <iostream>
#include <fstream>

Helper::Helper() {
    nam = new QNetworkAccessManager();
    connect(nam, &QNetworkAccessManager::finished, this, &Helper::onImageDownloaded_);
}

void Helper::download_() {
    QNetworkRequest request(url);
    nam->get(request);

}

void Helper::delete_() {
    QDir dir("/" + path);
    dir.remove("cat.jpg");

}

void Helper::onImageDownloaded_(QNetworkReply *reply) {
    QFile fout("/" + path + "cat.jpg");
    fout.open(QIODevice::ReadWrite);
    QTextStream stream(&fout);
    stream << reply->readAll();
    fout.close();
}
