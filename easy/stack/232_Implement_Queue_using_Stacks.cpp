//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _new.push(x);
    }

/** Removes the element from in front of queue and returns that element. */
    int pop() {
        moveNewToOld();
        int t = _old.top();
        _old.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        moveNewToOld();
        return _old.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _new.empty() && _old.empty();
    }

private:
    void moveNewToOld() {
        if (!_old.empty()) {
            return;
        }
        while (!_new.empty()) {
            _old.push(_new.top());
            _new.pop();
        }
    }

private:
    stack<int> _old, _new;
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    q.push(5);
    std::cout << q.peek() << std::endl;
    std::cout << q.empty() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.empty() << std::endl;
}