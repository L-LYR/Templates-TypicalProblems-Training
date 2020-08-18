/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = NULL, *cur = head;
        head = head->next; // attention!
        while(cur != NULL) {
            ListNode *next = cur->next;
            if (next == NULL) break;
            cur->next = next->next;
            next->next = cur;
            if (prev != NULL) {
                prev->next = next;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

