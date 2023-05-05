#ifndef DBUSADAPTER_H
#define DBUSADAPTER_H

#include <QDBusContext>
#include <QDBusMessage>
#include <QDBusReply>

class DBusAdapter : public QObject, QDBusContext
{
    Q_OBJECT

public:
    DBusAdapter();
    virtual ~DBusAdapter();

public slots:
    void installPackage(QString path);
    void quit();
};

#endif // DBUSADAPTER_H
