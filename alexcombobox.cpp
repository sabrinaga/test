#include "alexcombobox.h"

void AlexComboBox::myCurrentChanged(const QFont&){
    emit iChanged(this);
}
