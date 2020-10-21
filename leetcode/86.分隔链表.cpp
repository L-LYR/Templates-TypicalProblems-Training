/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = nullptr, *leftTail = nullptr;
        ListNode *right = nullptr, *rightTail = nullptr;
        ListNode *p = head;
        while (p != nullptr) {
            ListNode *next = p->next;
            if (p -> val >= x) {
                if (right == nullptr) {
                    right = rightTail = p;
                } else {
                    rightTail->next = p;
                    rightTail = rightTail->next;
                }
                rightTail->next = nullptr;
            } else {
                if (left == nullptr) {
                    left = leftTail = p;
                } else {
                    leftTail->next = p;
                    leftTail = leftTail->next;
                }
                leftTail->next = nullptr;
            }
            p = next;
        }
        if (leftTail != nullptr) {
            leftTail->next = right;
            return left;
        }
        else return right;
    }
};
// @lc code=end

