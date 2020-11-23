#ifndef REMOVE_H
#define REMOVE_H

#include "text_operation_child.h"

using namespace std;

//Наследование от TextOperationChild
class Remove : public text_operation_child {
public:
    Remove(const string& text, size_t position_place);

    //Насиледуемые методы
    void apply_operation(string& text) const override;//применить операцию удаления
    void undo(string& text) const override;//отменить операцию удаления
};

#endif // REMOVE_H
