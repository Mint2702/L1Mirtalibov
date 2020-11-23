#ifndef TEXT_OPERATION_PARENT
#define TEXT_OPERATION_PARENT_H

#include <string>

using namespace std;

class text_operation_parent {
public:
    virtual void apply_operation(string& text) const = 0;//Применеие операции
    virtual void undo(string& text) const = 0;//Отмена операции
};

#endif // TEXT_OPERATION_PARENT_H
