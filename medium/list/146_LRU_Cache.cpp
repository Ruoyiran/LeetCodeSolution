//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it
should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        int value = _map[key]->second;
        put(key, value);
        return value;
    }

    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            _cache.erase(_map[key]);
            _map.erase(key);
        }
        _cache.push_front({key, value});
        _map[key] = _cache.begin();
        if (_cache.size() > _capacity) {
            _map.erase(_cache.back().first);
            _cache.pop_back();
        }
    }

private:
    int _capacity;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
    list<pair<int, int>> _cache;
};

int main() {
    LRUCache cache(2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}