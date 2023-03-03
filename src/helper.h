#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void install_() const;

    Q_INVOKABLE void delete_() const;

    virtual ~Helper() {}

};

#endif // HELPER_H
