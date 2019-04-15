#ifndef ALEXLINEEDIT_H
#define ALEXLINEEDIT_H
#include <QLineEdit>

class AlexLineEdit: public QLineEdit{
    Q_OBJECT

public:
    AlexLineEdit(const QString& qstring):QLineEdit(qstring){}
    AlexLineEdit(QWidget* qw):QLineEdit(qw){}

signals:
    void iChanged(QObject*); //My own signal

public slots:
    //void myTextChanged(const QString&);
    void myEditingFinished();//For receiving its predefined signal. In its implementation, I emit my own signal.
};

#endif // ALEXLINEEDIT_H
