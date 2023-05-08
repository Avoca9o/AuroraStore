#include "dbusadaptor.h"
#include "mdm-applications.h"
#include <QDBusConnectionInterface>
#include <QDebug>
#include <QCoreApplication>

#include <unistd.h>

DBusAdaptor::DBusAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    const int m_autoclose_TIMEOUT_MS = 180 * 1000000;

    m_autoclose.setSingleShot(true);
    m_autoclose.setInterval(m_autoclose_TIMEOUT_MS);

    connect(&m_autoclose, SIGNAL(timeout()),
            this, SLOT(quit()));
    m_autoclose.start();
}

DBusAdaptor::~DBusAdaptor() {}

void DBusAdaptor::installPackage(QString path) {
    qDebug() << "I'm in\n";
    Sailfish::Mdm::Applications *mdmApplications = new Sailfish::Mdm::Applications();
    QObject::connect(mdmApplications->installPackage(path),
                     &Sailfish::Mdm::ApplicationOperation::finished,
                     [mdmApplications](Sailfish::Mdm::ApplicationOperation *operation) {
        mdmApplications->deleteLater();
    });
    qDebug() << "Packages installed\n";
}

void DBusAdaptor::quit() {
    QCoreApplication::quit();
}
