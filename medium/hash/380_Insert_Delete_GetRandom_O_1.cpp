//
// Created by ranpeng on 2020/4/29.
//
#include "common.h"

/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_valueMap.find(val) != _valueMap.end()) {
            return false;
        }
        _values.push_back(val);
        _valueMap[val] = _values.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (_valueMap.find(val) == _valueMap.end()) {
            return false;
        }
        int pos = _valueMap[val];
        int t = _values[_values.size()-1];
        _valueMap[t] = pos;
        _valueMap.erase(val);

        std::swap(_values[pos], _values[_values.size()-1]);
        _values.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (_values.empty()) {
            return 0;
        }
        int pos = rand() % _values.size();
        return _values[pos];
    }

private:
    unordered_map<int, int> _valueMap;
    vector<int> _values;
};

int main() {
    // Init an empty set.
    RandomizedSet randomSet;

    std::cout << randomSet.insert(0) << std::endl;
    std::cout << randomSet.insert(1) << std::endl;
    std::cout << randomSet.remove(0) << std::endl;
    std::cout << randomSet.insert(2) << std::endl;
    std::cout << randomSet.remove(1) << std::endl;
    std::cout << randomSet.getRandom() << std::endl;
}