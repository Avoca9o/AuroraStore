#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H

#include <QDBusContext>
#include <QDBusMessage>
#include <QDBusReply>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QTimer>

class DBusAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "dbusAdaptor.ru")
    Q_CLASSINFO("D-Bus Introspection", ""
"<interface name=\"dbusAdaptor.ru\">\n"
"   <method name=\"installPackage\">"
"       arg direction=\"in\" type=\"s\" name=\"path\""
"   </method>\n"
"</interface>\n")

public:
    DBusAdaptor(QObject *parent = nullptr);
    virtual ~DBusAdaptor();

public slots:
    void installPackage(QString path);
    void quit();

private:
    QTimer m_autoclose;
};

#endif // DBUSADAPTOR_H
