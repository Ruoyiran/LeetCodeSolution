//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].
*/
class NestedInteger {
public:
    NestedInteger(const vector<NestedInteger>& nums) : _list(nums), _integer(0), _isList(true), _isInteger(false) {
    }

    NestedInteger(int integer) : _integer(integer), _isList(false), _isInteger(true) {
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return _isInteger;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return _integer;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return _list;
    }

private:
    vector<NestedInteger> _list;
    int _integer;
    bool _isList;
    bool _isInteger;
};

class NestedIteratorV1 {
public:
    NestedIteratorV1(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
        iter = nums.begin();
    }

    int next() {
        if (hasNext()) {
            int n = *iter;
            ++iter;
            return n;
        }
        return 0;
    }

    bool hasNext() {
        return iter != nums.end();
    }

private:
    void flattenList(const vector<NestedInteger> &nestedList) {
        for(const auto& nested : nestedList) {
            if (nested.isInteger()) {
                nums.push_back(nested.getInteger());
            } else {
                flattenList(nested.getList());
            }
        }
    }

private:
    vector<int> nums;
    vector<int>::iterator iter;
};

class NestedIterator {
private:
    void flatten(const vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; --i) {
            auto t = nestedList[i];
            _nestedStack.push(t);
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        if (hasNext()) {
            int value = _nestedStack.top().getInteger(); _nestedStack.pop();
            return value;
        }
        return 0;
    }

    bool hasNext() {
        while (!_nestedStack.empty()) {
            if (_nestedStack.top().isInteger()) {
                return true;
            }
            auto tmp = _nestedStack.top(); _nestedStack.pop();
            flatten(tmp.getList());

        }
        return false;
    }

private:
    stack<NestedInteger> _nestedStack;
};

int main() {
    vector<NestedInteger> nestedList;
    nestedList.push_back(NestedInteger({1,2}));
    nestedList.push_back(NestedInteger(2));
    nestedList.push_back(NestedInteger({1, NestedInteger({1,4,5,62,3})}));
    auto iter = NestedIterator(nestedList);
    while (iter.hasNext()) {
        std::cout << iter.next() << " ";
    }
    std::cout << std::endl;
    return 0;
}