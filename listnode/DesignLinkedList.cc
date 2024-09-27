//
// Ref: https://leetcode.cn/problems/design-linked-list/description/
// Created by Zhaohong Liu on 2024/9/27.
//

#include "BaseSolution.h"

class DesignLinkedList final : public BaseSolution {
public:
    DesignLinkedList() : BaseSolution(707, "Design Linked List") {}

    void runSolution() override {
        displayProblemInfo();
    }
};

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        explicit LinkedNode(const int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        dummyHead_ = new LinkedNode(0);
        size_ = 0;
    }

    [[nodiscard]] int get(int index) const {
        if (index > size_ - 1 || index < 0) {
            return -1;
        }
        const auto* cur = dummyHead_->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(const int val) {
        auto* newNode = new LinkedNode(val);
        newNode->next = dummyHead_->next;
        dummyHead_->next = newNode;
        size_ += 1;
    }

    void addAtTail(const int val) {
        auto* newNode = new LinkedNode(val);
        auto* cur = dummyHead_;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        size_ += 1;
    }

    void addAtIndex(int index, const int val) {
        if (index > size_ || index < 0) {
            return;
        }
        auto* newNode = new LinkedNode(val);
        auto* cur = dummyHead_;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size_ += 1;
    }

    void deleteAtIndex(int index) {

    }

private:
    LinkedNode *dummyHead_;
    int size_;
};
