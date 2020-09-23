/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *f, *b, *r;
        f = head;
        // get length
        int n = 0;
        while (f != nullptr) {
            f = f->next;
            n++;
        }
        k %= n;
        if (k == 0) return head;
        // quick-slow pointers
        f = head;
        for (int i = 0; i < k; ++i) {
            f = f->next;
        }
        b = head;
        while (f->next != nullptr) {
            f = f->next;
            b = b->next;
        }
        r = b->next;
        b->next = nullptr;
        f->next = head;
        return r;
    }
};
// @lc code=end

