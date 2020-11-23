#include "remove.h"

using namespace std;

//Конструктор инициализации
Remove::Remove(const string& text, size_t position_place) : text_operation_child(text, position_place) { }

//Применение операции(удаление)
void Remove::apply_operation(string &text_in) const {
    text_in.erase(position, text.size());
}

//Отмена операции удаления
void Remove::undo(string &text_in) const {
    text_in.insert(position, text);
}
