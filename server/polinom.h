#ifndef POLINOM_H
#define POLINOM_H

#include <QString>
#include <number.h>

class polinom
{
private:
    number a;
    number b;
    number c;
public:
    polinom();
    polinom(number,number,number);
    void set(number,number,number);
    void roots(short &, number &, number &);
    number value(number x);
    QString standart();
    QString canon();
};

#endif // POLINOM_H
