/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *cur = head, *rev = NULL;
        while (cur != NULL) {
            next = cur->next;
            cur->next = rev;
            rev = cur;
            cur = next;
        }
        return rev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *cur_list = NULL, *cur_head = head, // control the ready for reversing part
                 *ans = NULL, *tail = NULL; // control the reversed part
        while (true) {
            ListNode *p = cur_head, *prev = NULL;
            int n = 0;
            while (n < k && p != NULL) {
                prev = p;
                p = p->next;
                ++n;
            }
            if (prev != NULL) prev->next = NULL;
            cur_list = cur_head;
            cur_head = p;
            
            if (cur_head == NULL && n < k) {
                if (ans == NULL) {
                    return head;
                } else {
                    tail->next = cur_list;
                    return ans;
                }
            }

            if (ans == NULL) {
                ans = reverseList(cur_list);
            } else {
                tail->next = reverseList(cur_list);
            }
            tail = cur_list;
        }
    }
};
// @lc code=end

