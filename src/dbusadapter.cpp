#include "dbusadapter.h"
#include "mdm-applications.h"
#include <QDBusConnectionInterface>
#include <QDebug>

const char *SERVICE_NAME = "ru.auroraos.aurorastore";
const char *OBJECT_PATH = "/ru/aurorsos/aurorastore";

DBusAdapter::DBusAdapter()
{
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (!connection.registerObject(OBJECT_PATH, this)) {
        qFatal("Cannot register object at %s", SERVICE_NAME);
    }

    if (!connection.registerService(SERVICE_NAME)) {
        qFatal("Cannot register D-Bus service at %s", SERVICE_NAME);
    }

    qDebug("DBus adapter created\n");
}

DBusAdapter::~DBusAdapter() {}

void DBusAdapter::installPackage(const QString path) {
    qDebug() << "I'm in\n";
    Sailfish::Mdm::Applications *mdmApplications = new Sailfish::Mdm::Applications();
    QObject::connect(mdmApplications->installPackage(path),
                     &Sailfish::Mdm::ApplicationOperation::finished,
                     [mdmApplications](Sailfish::Mdm::ApplicationOperation *operation) {
        mdmApplications->deleteLater();
    });
    qDebug() << "Packages installed\n";
}

void DBusAdapter::quit() {

}