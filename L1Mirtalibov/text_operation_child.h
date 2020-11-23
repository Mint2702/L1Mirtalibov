#ifndef TEXT_OPERATION_CHILD_H
#define TEXT_OPERATION_CHILD_H

#include "text_operation_parent.h"

using namespace std;

//Наследование от класса text_operation_parent
class text_operation_child : public text_operation_parent {
public:
    text_operation_child(const string& text, size_t position);
protected:
    string text;
    size_t position = 0;
};

#endif // TEXT_OPERATION_CHILD_H
