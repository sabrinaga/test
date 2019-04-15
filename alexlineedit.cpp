#include "alexlineedit.h"

//void AlexLineEdit::myTextChanged(){
void AlexLineEdit::myEditingFinished(){
    emit iChanged(this);
}
