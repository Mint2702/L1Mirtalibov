#include "insert.h"

using namespace std;

//Конструктор инициализации
Insert::Insert(const string& text, size_t position_):text_operation_child(text, position_) { }

//Применение операции(вставка)
void Insert::apply_operation(string &text_in) const {
    text_in.insert(position, text);
}

//Отмена операции вставки
void Insert::undo(string &text_in) const {
    text_in.erase(position, text.size());
}
