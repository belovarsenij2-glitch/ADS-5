// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
public:
    void push_back(T val);
    void pop_back();
    T peek();
    bool empty();
};

#endif  // INCLUDE_TSTACK_H_
