/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// O(min(n, m))
// n = ListLength(l1)
// m = ListLength(l2)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *ans, *last;

        if (l1->val < l2->val) {
            ans = l1;
            l1 = l1->next;
        } else {
            ans = l2;
            l2 = l2->next;
        } 

        last = ans;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }

        if (l1 != NULL) last->next = l1;
        if (l2 != NULL) last->next = l2;

        return ans;
    }
};
// @lc code=end