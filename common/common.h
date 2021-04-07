#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ANSWER,
    STANDART_REQUEST,
    STANDART_ANSWER,
    CANON_REQUEST,
    CANON_ANSWER,
    ROOTS_REQUEST,
    ROOTS_ANSWER,
};

extern const QChar separator;

QString& operator<< (QString&,const QString&);

#endif // COMMON_H
