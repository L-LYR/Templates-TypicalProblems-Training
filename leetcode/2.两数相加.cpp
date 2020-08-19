/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// Simulation
// The procedure is just like the merge of two sorted linked list.
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = NULL, *last = NULL;
        int curVal = 0, carry = 0;
        while (l1 != NULL && l2 != NULL) {
            curVal = l1->val + l2->val + carry;
            carry = curVal / 10;
            if (ans == NULL) {
                ans = new ListNode(curVal % 10);
                last = ans;
            }
            else {
                ListNode *curNode = new ListNode(curVal % 10);
                last->next = curNode;
                last = curNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            curVal = l1->val + carry;
            carry = curVal / 10;

            ListNode *curNode = new ListNode(curVal % 10);
            last->next = curNode;
            last = curNode;

            l1 = l1->next;
        }
        while (l2 != NULL) {
            curVal = l2->val + carry;
            carry = curVal / 10;

            ListNode *curNode = new ListNode(curVal % 10);
            last->next = curNode;
            last = curNode;

            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode *curNode = new ListNode(carry);
            last->next = curNode;
            last = curNode;
        }
        return ans;
    }
};
// @lc code=end
