#ifndef REPLACE_H
#define REPLACE_H

#include "remove.h"
#include "insert.h"

using namespace std;

//Класс замены строки, наследуемый от TextOperationParent, Remove, Insert
class Replace : public text_operation_parent, private Remove, private Insert {
public:
    //Конструктор инициализации
    Replace(const string& old, const string& new_text, size_t position_place);

    //Насиледуемые методы
    void apply_operation(string& text) const override;
    void undo(string& text) const override;
};

#endif // REPLACE_H

