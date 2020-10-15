/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *l = head, *r = head, *res = NULL;
        while (r != NULL) {
            ListNode *cur = r;
            while (r != NULL && cur->val == r->val) {
                r = r->next;
            }
            if (r == cur->next) {
                if (res == NULL) {
                    res = cur;
                    l = res;
                } else {
                    l->next = cur;
                    l = l->next;
                }
                l->next = NULL;
            }
        }
        return res;
    }
};
// @lc code=end

