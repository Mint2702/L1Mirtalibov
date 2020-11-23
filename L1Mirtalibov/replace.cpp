#include "replace.h"

using namespace std;

//Конструктор инициализации
Replace::Replace(const string& old_, const string& new_, size_t position_place):Remove(old_, position_place), Insert(new_, position_place) { }

//Применение операции(замена текста)
void Replace::apply_operation(string &text) const {
    Remove::apply_operation(text);
    Insert::apply_operation(text);
}

//Отмена операции замены текста
void Replace::undo(string &text) const {
    Insert::undo(text);
    Remove::undo(text);
}
