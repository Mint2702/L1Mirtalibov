#ifndef INSERT_H
#define INSERT_H

#include "text_operation_child.h"

using namespace std;

//Наследование от TextOperationChild
class Insert : public text_operation_child {
public:
    Insert(const string& text, size_t position_place);//конструктор инициализации

    //Наследуемые методы
    void apply_operation(string& text) const override;//переопределение(применение операции вставки текста)
    void undo(string& text) const override;//переопределение(отмена вставки текста)
};

#endif // INSERT_H
