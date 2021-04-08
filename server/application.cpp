#include "application.h"




Application::Application(int argc, char *argv[])
    : QCoreApplication(argc,argv)
{
    CommParams pars = { QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new Communicator(pars);
    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void Application::recieve(QByteArray msg)
{
    QString answer, s;
    short f;
    number a, b, c, x, v, x1, x2;
    msg >> a >> b >> c;
    polinom p(a,b,c);
    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    switch (t)
    {
    case VALUE_REQUEST:
        msg = msg.right(msg.length()-pos-1);
        msg >> x;
        v = p.value(x);
        s << (QString)x << (QString)v;
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;
        break;
    case STANDART_REQUEST:
        s << QString::fromStdString(p.standart());
        answer<<QString().setNum(STANDART_ANSWER)<<s;
        break;
    case CANON_REQUEST:
        s<<QString::fromStdString(p.canon());
        answer<<QString().setNum(CANON_ANSWER)<<s;
        break;
    case ROOTS_REQUEST:
        p.roots(f,x1,x2);
        //qDebug() << "f = " << f;
        //qDebug() << "x1 = " << x1;
        //qDebug() << "x2 = " << x2;
        //s << QString::number(f);
        switch (f)
        {
        case 1:
            s << (QString)x1 + ", " + (QString)x2;
            break;
        case 2:
            s << (QString)x1;
            break;
        case 3:
            s << "У полинома нет вещественных корней";
            break;
        case 4:
            s << "Корни полинома не рациональные";
            break;
        case 5:
            s << "Один корень не рациональный";
            break;
        default:
            return;
        }
        answer<<QString().setNum(ROOTS_ANSWER)<<s;
        break;
    default:
        return;
    }
    comm->send(QByteArray().append(answer.toUtf8()));
}
