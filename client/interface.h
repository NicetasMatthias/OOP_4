#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

#include <common.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
    void answer(QByteArray);

private slots:
    void on_pushButton_roots_clicked();

    void on_pushButton_value_clicked();

    void on_pushButton_standart_clicked();

    void on_pushButton_canon_clicked();

signals:
    void request(QString);

private:
    Ui::Interface *ui;

    void form_request(int);
};
#endif // INTERFACE_H
