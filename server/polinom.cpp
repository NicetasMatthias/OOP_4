#include "polinom.h"

polinom::polinom()
{
    a=1;
    b=0;
    c=0;
}

polinom::polinom(number A,number B,number C)
{

}

void polinom::set(number A,number B,number C)
{
    a=A;
    b=B;
    c=C;
}

void polinom::roots(short &flag, number &x1, number &x2)
{
    number d;
                    /*
                    Значения flag
                    1 - два разных корня
                    2 - два одинаковых корня
                    3 - нет корней
                    4 - оба корня не рациональные
                    5 - один корень не рациональный
                    */
    d=polinom::b*polinom::b-4*polinom::a*polinom::c;

    if (d<0)
    {
        flag = 3;
        return;
    }
    else if (d==0)
    {
        x1=(-polinom::b)/(2*polinom::a);
        if (polinom::value(x1)==0)
        {
            flag = 2;
            return;
        }
        else
        {
            flag = 4;
            return;
        }
    }
    x1=(-polinom::b+sqrt(d))/(2*polinom::a);
    x2=(-polinom::b-sqrt(d))/(2*polinom::a);
    if ((polinom::value(x1)==0)&&(polinom::value(x2)==0))
    {
        flag = 1;
        return;
    }
    else if (polinom::value(x1)==0)
    {
        flag = 5;
        return;
    }
    else if (polinom::value(x2)==0)
    {
        x1=x2;
        flag = 5;
        return;
    }
    else
    {
        flag = 4;
        return;
    }
}

number polinom::value(number x)
{
    return polinom::a*x*x+polinom::b*x+polinom::c;
}

QString polinom::standart()
{
    std::stringstream ss;

    ss << std::showpos << polinom::a << "*x^2" << polinom::b << "*x" << polinom::c << std::endl;
    return QString::fromStdString(ss.str());
}

QString polinom::canon()
{
    std::stringstream ss;
    short flag;
    number rts[2];
    polinom::roots(flag,rts[0],rts[1]);

    switch (flag)
    {
    case 1:
        ss << std::showpos << polinom::a << "*(x" << -rts[0] << ")*(x" << -rts[1] << ")";
        break;
    case 2:
        ss << std::showpos << polinom::a << "*(x" << -rts[0] << ")^2";
        break;
    case 3:
        ss << "У полинома нет вещественных корней";
        break;
    case 4:
        ss << "Корни полинома не рациональные";
        break;
    case 5:
        ss << "Один из корней полинома не рациональный";
        break;
    default:
        ss << "Неизвестная ошибка при вычислении корней";
        break;
    }
    return QString::fromStdString(ss.str());
}
