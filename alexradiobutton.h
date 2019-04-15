#ifndef ALEXRADIOBUTTON_H
#define ALEXRADIOBUTTON_H
#include <QRadioButton>

class AlexRadioButton: public QRadioButton{
    Q_OBJECT

public:
    AlexRadioButton(QWidget* qw):QRadioButton(qw){}
    AlexRadioButton(QString qs):QRadioButton(qs){}

signals:
    void iChanged(QObject*); //My own signal

public slots:
    void myStateChanged();//For receiving its predefined signal. In its implementation, I emit my own signal.
};
#endif // ALEXCHECKBOX_H
