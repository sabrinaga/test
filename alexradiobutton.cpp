#include "alexradiobutton.h"

void AlexRadioButton::myStateChanged(){
    emit iChanged(this);
}


