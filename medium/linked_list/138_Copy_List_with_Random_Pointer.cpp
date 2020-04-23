//
// Created by ranpeng on 2020/4/16.
//
#include "common.h"

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Example 1:
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

Note:

You must return the copy of the given head as a reference to the cloned list.
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, int> m;
        auto headBak = head;
        int index = 0;
        vector<Node*> nodes;
        while (head != NULL) {
            nodes.push_back(new Node(head->val));
            m[head] = index++;
            head = head->next;
        }
        head = headBak;
        index = 0;

        Node* newHeadDummy = new Node(0);
        Node* newHead = newHeadDummy;
        while (head != NULL) {
            if (head->random != NULL) {
                int i = m[head->random];
                nodes[index]->random = nodes[i];
            }
            newHead->next = nodes[index];
            newHead = newHead->next;
            head = head->next;
            ++index;
        }
        newHead = newHeadDummy->next;
        delete newHeadDummy;
        return newHead;
    }
};

void printRandomList(Node *pNode);

void deleteRandomList(Node *pNode);

int main() {
    vector<int> nums = {7,13,11,10,1};
    Node* head = NULL;
    Node* tmp = NULL;
    for (auto n : nums) {
        if (head == NULL) {
            head = new Node(n);
            tmp = head;
        } else {
            tmp->next = new Node(n);
            tmp = tmp->next;
        }
    }
    head->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    auto newHead = Solution().copyRandomList(head);
    printRandomList(head);
    cout << "newHead:\n";
    printRandomList(newHead);
    deleteRandomList(head);
    deleteRandomList(newHead);
    return 0;
}

void deleteRandomList(Node *pNode) {
    while (pNode != NULL) {
        auto tmp = pNode->next;
        delete pNode;
        pNode = tmp;
    }
}

void printRandomList(Node *head) {
    while (head != NULL) {
        auto tmp = head->next;
        cout << head->val;
        if (head->random != NULL) {
            cout << " " << head->random->val << endl;
        } else {
            cout << " null\n";
        }
        head = tmp;
    }
}
