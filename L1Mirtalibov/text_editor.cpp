#include "text_editor.h"

#include <iostream>

#include "remove.h"
#include "insert.h"
#include "replace.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

text_editor::text_editor() { }

void text_editor::remove(size_t position_place, size_t length) {
    if ((position_place + length > m_text.size()) || (length == 0)) {
        cerr << "Couldn't remove\n";
        return;
    }
    redo_stack.clear();
    apply_operation(make_shared<Remove>(m_text.substr(position_place, length), position_place));
}

void text_editor::insert(const string &text, size_t position_place) {
    if ((position_place > m_text.size()) || text.empty()) {
        cerr << "Couldn't insert\n";
        return;
    }
    redo_stack.clear();
    apply_operation(make_shared<Insert>(text, position_place));
}

void text_editor::replace(const string &new_, size_t position_place, size_t length) {
    if ((position_place + length > m_text.size()) || new_.empty()) {
        cerr << "Couldn't replace\n";
        return;
    }
    redo_stack.clear();
    apply_operation(make_shared<Replace>(m_text.substr(position_place, length), new_, position_place));
}

void text_editor::undo() {
    auto operation = undo_stack.top();
    undo_stack.pop();
    operation->undo(m_text);
    redo_stack.push(move(operation));
}

void text_editor::redo() {
    auto operation = redo_stack.top();
    redo_stack.pop();
    operation->apply_operation(m_text);
    undo_stack.push(move(operation));
}

const string &text_editor::text() const {
    return m_text;
}

void text_editor::apply_operation(shared_ptr<text_operation_parent>&& operation_) {
    operation_->apply_operation(m_text);
    undo_stack.push(move(operation_));
}
