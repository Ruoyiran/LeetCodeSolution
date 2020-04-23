//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the
median is the mean of the two middle value.

For example,

[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNumV1(int num) {
        int pos = binarySearch(num);
        _data.insert(_data.begin()+pos, num);
    }

    double findMedianV1() {
        if (_data.empty()) {
            return 0.0;
        }
        int n = _data.size();
        if (_data.size() & 0x1) {
            return _data[n/2];
        } else {
            return (_data[(n-1)/2] + _data[n/2]) / 2.0;
        }
    }

    void addNum(int num) {
        lower.push(num);
        higher.push(lower.top()); // 取出最大值，存放到最小堆里
        lower.pop(); // balance
        if (lower.size() < higher.size()) {
            lower.push(higher.top());
            higher.pop();
        }
    }

    double findMedian() {
        if (lower.size() > higher.size()) {
            return lower.top();
        } else {
            return (lower.top()+higher.top())/2.0;
        }
    }

private:
    int binarySearch(int num) {
        if (_data.empty()) {
            return 0;
        }
        int left = 0, right = _data.size()-1;
        while (left <= right) {
            int mid = (left+right) / 2;
            if (_data[mid] == num) {
                return mid+1;
            } else if (_data[mid] < num) {
                ++left;
            } else {
                --right;
            }
        }
        return left;
    }
private:
    vector<int> _data;
    priority_queue<int> lower; // 最大堆，存放一半小的数
    priority_queue<int, vector<int>, greater<int>> higher; // 最小堆，存放一半大的数
};

int main() {
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    cout << finder.findMedian() << endl;
    finder.addNum(3);
    cout << finder.findMedian() << endl;
    return 0;
}
