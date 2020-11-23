#include "text_operation_child.h"

using namespace std;

//Конструктор инициализации
text_operation_child::text_operation_child(const string &text, size_t position)
{
    this->text = text;
    this->position = position;
}
