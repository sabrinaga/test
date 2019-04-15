#include "horizontalslider.h"

void HorizontalSlider::myStateChanged(int){
    emit iChanged(this);
}
