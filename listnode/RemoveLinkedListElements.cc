//
// Ref: https://leetcode.cn/problems/remove-linked-list-elements/description/
// Ref: https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
// Created by Zhaohong Liu on 2024/9/27.
//

#include "BaseSolution.h"
#include "include/ListNode.h"

class RemoveLinkedListElements final : public BaseSolution {
public:
    RemoveLinkedListElements() : BaseSolution(203, "Remove Linked List Elements") {}

    static ListNode* removeElements(ListNode* head, const int val) {
        auto* dummyHead = new ListNode(0);
        dummyHead->next = head;

        auto* cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                const auto* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    void runSolution() override {
        displayProblemInfo();
        // init with test 1: [1,2,6,3,4,5,6]
        auto* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);

        // test
        constexpr int val = 6;
        std::cout << "The input linked list is: ";
        showListNode(*head);
        std::cout << "The value to remove is: " << val << std::endl;
        removeElements(head, val);
        std::cout << "The output linked list is: ";
        showListNode(*head);
    }
};