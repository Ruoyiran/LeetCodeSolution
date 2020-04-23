//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x <= stack2.top()) {
            stack2.push(x);
        }
    }

    void pop() {
        if (stack1.top() == stack2.top()) {
            stack2.pop();
        }
        stack1.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return stack2.top();
    }
private:
    stack<int> stack1, stack2;
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
}