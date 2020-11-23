#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "stack.h"
#include "text_operation_child.h"

using namespace std;

class text_editor {
public:
    //Конструктор по умолчанию
    text_editor();

    //Шаг назад
    void undo();

    //Шаг вперед
    void redo();

    //Вставка(Ctrl+V)
    void insert(const string& text, size_t position_place);

    //Удаление строки
    void remove(size_t position_place, size_t length);

    //Замена строки
    void replace(const string& new_, size_t position_place, size_t length);

    const string& text() const;

    stack<shared_ptr<text_operation_parent> > undo_stack;//Умный указатель в стек undo
    stack<shared_ptr<text_operation_parent> > redo_stack;
private:
    string m_text;



    //Применение операции
    void apply_operation(shared_ptr<text_operation_parent>&& operation);
};

#endif // TEXT_EDITOR_H
