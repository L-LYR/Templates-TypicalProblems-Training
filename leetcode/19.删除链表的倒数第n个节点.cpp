/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // empty list or no node
        if (head == NULL || n == 0) return head;

        ListNode *prev = head, *last_n = head, *last;

        // important
        // make the distance between prev and last_n be n
        for (int i = 0; i < n; ++i) {
            prev = prev->next;
        }

        // delete the fist node
        if (prev == NULL) return head->next;

        while (prev != NULL) {
            prev = prev->next;
            last = last_n; // last points to the parent node of last_n's
            last_n = last_n->next;
        }
        
        last->next = last_n->next;

        return head;
    }
};
// @lc code=end

