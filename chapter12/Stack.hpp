/**************************************************************
 *Stack.hpp
 *-sfer and more convenient stack class
 **************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <deque>
#include <exception>

template <typename T>
class Stack {
    private:
        std::deque<T> container;

    public:
    //exception class fro pop() and top()
    class ReadEmptyStack : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "read empty stack ";
        }
    };

    //number of elements
    typename std::deque<T>::size_type size() const {
        return container.size();
    }

    //is stack empty?
    bool empty() const {
        return container.empty();
    }

    //push element into the stack
    void push(const T &elem) {
        container.push_back(elem);
    }

    //pop element out of the stack and return its value
    T pop() {
        if (container.empty()) {
            throw ReadEmptyStack();
        }

        T elem(container.back());
        container.pop_back();
        return elem;
    }

    //return value of next element
    T &top() {
        if (container.empty()) {
            throw ReadEmptyStack();
        }

        return container.back();
    }
};

#endif
