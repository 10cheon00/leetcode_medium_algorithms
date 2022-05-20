#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* node = new ListNode(0, head), * copiedHead = nullptr, *tempNode, *nextNode;
        while (true) {
            if (node->next == nullptr || node->next->next == nullptr) {
                break;
            }
            tempNode = node->next;
            nextNode = node->next->next->next;
            node->next = node->next->next;
            node->next->next = tempNode;
            tempNode->next = nextNode;
            if (copiedHead == nullptr) {
                copiedHead = node->next;
            }
            node = node->next->next;
        }
        return copiedHead;
    }
};