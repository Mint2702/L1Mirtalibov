#ifndef STACK_H
#define STACK_H

#include <istream>

using namespace std;

//Класс стека
template<typename template_class> class stack {
public:
    //Дефолтные конструктор и деструктор
    stack() = default;
    ~stack() = default;

    //Конструкторы инициализации и копирование
    stack(const stack& other);
    stack(stack&& other) = default;

    stack& operator=(const stack& other_stack);
    stack& operator=(stack&& other_stack) = default;
    template_class& top();

    //Различные действия со стеком(добавить в конец, снять с конца и вернуть, очистить)
    void pop();
    void push(const template_class& element);
    void push(template_class&& element);
    void clear();

    //Размер стека
    size_t size() const;

    //Проверка на пустой стек
    bool is_empty() const;


private:
    void copy(const stack& other_);

    //Класс элемента стека
    class stack_element {
    public:
        //Конструкторы класса
        stack_element() = delete;
        stack_element(const template_class& value, unique_ptr<stack_element>&& next) :
            m_value{value}, m_next{move(next)} { }
        stack_element(template_class&& value, unique_ptr<stack_element>&& next) :
            m_value{move(value)}, m_next{move(next)} { }

        //Методы класса
        template_class& value() { return m_value; }
        unique_ptr<stack_element>& next() { return m_next; }
    private:
        //Поля класса
        template_class m_value;
        unique_ptr<stack_element> m_next{nullptr};
    };

    unique_ptr<stack_element> m_top = nullptr;
    size_t m_size = 0;
};

template<typename template_stack> void stack<template_stack>::copy(const stack& other_) {
    if (other_.m_top == nullptr) {
        return;
    }
    stack<template_stack> temp;
    auto t = other_.m_top.get();
    do {
        temp.push(t->value());
        t = t->next().get();
    } while (t != nullptr);
    t = temp.m_top.get();
    do {
        push(t->value());
        t = t->next().get();
    } while (t != nullptr);
}

template<typename template_stack> stack<template_stack>::stack(const stack& other_) {
    copy(other_);
}

template<typename template_stack> stack<template_stack>& stack<template_stack>::operator=(const stack& other_) {
    if (&other_ != this) {
        clear();
        copy(other_);
    }
    return *this;
}

template<typename template_stack> template_stack& stack<template_stack>::top() {
    if (m_top == nullptr) {
        throw out_of_range("Stack is empty");
    }
    return m_top->value();
}

template<typename template_stack> void stack<template_stack>::pop() {
    if (m_top != nullptr) {
        m_top = move(m_top->next());
        --m_size;
    }
}

template<typename template_stack> void stack<template_stack>::push(const template_stack& value_) {
    m_top = make_unique<stack_element>(value_, move(m_top));
    ++m_size;
}

template<typename template_stack> void stack<template_stack>::push(template_stack&& value_) {
    m_top = make_unique<stack_element>(move(value_), move(m_top));
    ++m_size;
}

template<typename template_stack> size_t stack<template_stack>::size() const {
    return m_size;
}

template<typename template_stack> bool stack<template_stack>::is_empty() const {
    return m_top == nullptr;
}

template<typename template_stack> void stack<template_stack>::clear() {
    m_top = nullptr;
    m_size = 0;
}

#endif // STACK_H
