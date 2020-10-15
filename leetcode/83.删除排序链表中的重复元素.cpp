/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
 //O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* l = head, *r = head;
        while (r != NULL) {
            int cur = r->val;
            while (r != NULL && r->val == cur) {
                r = r->next;
            }
            l->next = r;
            l = l->next;
        }
        return head;
    }
};
// @lc code=end

