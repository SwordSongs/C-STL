/**************************************************************
 *Queue.hpp
 *-sfer and more convenient stack class
 **************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <deque>
#include <exception>

template <typename T>
class Queue {
    private:
    std::deque<T> container;

    public:
    //exception class fro pop() and top()
    class ReadEmptyQueue : public std::exception {
        public:
        virtual const char *what() const throw() {
            return "read empty queue ";
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
            throw ReadEmptyQueue();
        }

        T elem(container.front());
        container.pop_front();
        return elem;
    }

    //return value of next element
    T &front() {
        if (container.empty()) {
            throw ReadEmptyQueue();
        }

        return container.front();
    }

    //return value of last element
    T &back() {
        if (container.empty()) {
            throw ReadEmptyQueue();
        }

        return container.back();
    }
};

#endif
