//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        _q.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = _q.back();
        _q.pop_back();
        return t;
    }

    /** Get the top element. */
    int top() {
        return _q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _q.empty();
    }

private:
    deque<int> _q;
};

int main() {
    MyStack obj;
    obj.push(1);
    std::cout << obj.pop() << std::endl;
    std::cout << obj.empty() << std::endl;
    obj.push(2);
    obj.push(3);
    obj.push(4);
    std::cout << obj.top() << std::endl;
    std::cout << obj.pop() << std::endl;
    std::cout << obj.empty() << std::endl;
    std::cout << obj.pop() << std::endl;
    std::cout << obj.empty() << std::endl;
    std::cout << obj.pop() << std::endl;
    std::cout << obj.empty() << std::endl;
    return 0;
}