#ifndef ALEXFONTCOMBOBOX_H
#define ALEXFONTCOMBOBOX_H
#include <QComboBox>

class AlexComboBox: public QComboBox{
    Q_OBJECT

public:
    AlexComboBox(QWidget* qw):QComboBox(qw){}

signals:
    void iChanged(QObject*); //My own signal

public slots:
    void myCurrentChanged(const QFont&);//For receiving its predefined signal. In its implementation, I emit my own signal.
};

#endif // ALEXCOMBOBOX_H
