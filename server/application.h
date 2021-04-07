#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>
#include <QObject>

#include <communicator.h>
#include <polinom.h>
#include <common.h>

class Application : public QCoreApplication
{
    Q_OBJECT

    Communicator *comm;

public:
    Application(int,char**);

public slots:

    void recieve(QByteArray);
};

#endif // APPLICATION_H
