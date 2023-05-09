#include "applicationlistviewmanager.h"
#include "helper.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QThread>
#include <QDBusMessage>
#include <QtDBus/QDBusConnection>

ApplicationListViewManager::ApplicationListViewManager(QObject *parent)
{
}

void ApplicationListViewManager::download() {
    QFile file(path + "me/defaultuser/applications.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open applications.json file\n";
        exit(0);
    }
    QTextStream file_text(&file);
    QString json_string;
    json_string = file_text.readAll();
    file.close();
    applicationsBytes = json_string.toLocal8Bit();
    i = 0;

    auto json_doc = QJsonDocument::fromJson(applicationsBytes);
    if (!json_doc.isArray()) {
        qDebug() << "JSON doc is not an array.\n";
        exit(0);
    }
    QJsonArray json_array = json_doc.array();
    for (int j = 0; j < json_array.count(); ++j) {
        auto obj = json_array.at(j).toObject();
        auto map = obj.toVariantMap();
        Application app;
        app.name = map["name"].toString();
        app.version = map["version"].toString();
        app.author = map["developer"].toString();
        app.longDescription = map["long_description"].toString();
        base.append(app);
    }
}

bool ApplicationListViewManager::hasNext() {
    return i != base.size();
}

QString ApplicationListViewManager::getId() {
    return QString::number(i);
}

QString ApplicationListViewManager::getName(QString id) {
    if (id == "") {
        return base[i].name;
    }
    return base[id.toInt() - 1].name;
}

QString ApplicationListViewManager::getVersion(QString id) {
    if (id == "") {
        return base[i].version;
    }
    return base[id.toInt() - 1].version;
}

QString ApplicationListViewManager::getLongDesctiption(QString id) {
    if (id == "") {
        return base[i].longDescription;
    }
    return base[id.toInt() - 1].longDescription;
}

QString ApplicationListViewManager::getAuthor(QString id) {
    if (id == "") {
        return base[i++].author;
    }
    return base[id.toInt() - 1].author;
}

void ApplicationListViewManager::invoke(QString id) {
//    QDBusMessage message = QDBusMessage::createMethodCall("dbusAdaptor.ru",
//                                                          "/dbusAdaptor",
//                                                          "dbusAdaptor.ru",
//                                                          "installPackage");

//    QList<QVariant> args;
//    args.append(path + "me/defaultuser/" + id + ".rpm");
//    message.setArguments(args);

//    auto replpy = QDBusConnection::sessionBus().call(message);
//    qDebug() << replpy.errorMessage();
}

ApplicationListViewManager::~ApplicationListViewManager() {}
