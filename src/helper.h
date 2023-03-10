#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper : public QObject
{
    Q_OBJECT



public:
    Helper();

    Q_INVOKABLE void install_();

    Q_INVOKABLE void delete_();

    Q_INVOKABLE int getx_() const;

    virtual ~Helper() {}

    int x;

};

#endif // HELPER_H
