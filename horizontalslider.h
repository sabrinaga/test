#ifndef HORIZONTALSLIDER_H
#define HORIZONTALSLIDER_H
#include <QSlider>

class HorizontalSlider: public QSlider{
    Q_OBJECT

public:
    HorizontalSlider(QWidget* qw):QSlider(qw){}
    //HorizontalSlider(QString qs):QSlider(qs){}

signals:
    void iChanged(QObject*); //My own signal

public slots:
    void myStateChanged(int);//For receiving its predefined signal. In its implementation, I emit my own signal.
};
#endif // HORIZONTALSLIDER_H
