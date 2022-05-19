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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // handling exception
        if (n == 1 && head->next == nullptr) {
            delete head;
            return nullptr;
        }
        ListNode* copiedHead = head;
        ListNode* targetNode = head;
        int index = 1;
        // move forward and calculate index of target
        while (copiedHead->next) {
            if (index > n) {
                targetNode = targetNode->next;
            }
            index++;
            copiedHead = copiedHead->next;
        }
        // handling exception
        if (targetNode->next == nullptr) {
            delete targetNode;
        }
        else if (n == index) {
            ListNode* tempNode = targetNode->next;
            delete targetNode;
            head = tempNode;
        }
        else {
            ListNode* tempNode = targetNode->next->next;
            delete targetNode->next;
            targetNode->next = tempNode;
        }

        return head;
    }
};