#ifndef DBUSADAPTER_H
#define DBUSADAPTER_H

#include <QDBusContext>
#include <QDBusMessage>
#include <QDBusReply>
#include <QtDBus/QDBusAbstractAdaptor>

class DBusAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.auroraos.project1")
    Q_CLASSINFO("D-Bus Introspection", ""
"<interface name=\"ru.auroraos.project1\">\n"
"   <method name=\"installPackage\">"
"       arg direction=\"in\" type=\"s\" name=\"path\""
"   </method>\n"
"</interface>\n")

public:
    DBusAdapter(QObject *parent = nullptr);
    virtual ~DBusAdapter();

public slots:
    void installPackage(QString path);
};

#endif // DBUSADAPTER_H
