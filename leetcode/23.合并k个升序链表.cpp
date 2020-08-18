/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

// O(knlogk)
class Solution {
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

    ListNode* conquer(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = (r - l) / 2 + l;
        return mergeTwoLists(conquer(lists, l, mid), conquer(lists, mid + 1, r));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();
        if (n == 0) return {};
        if (n == 1) return lists[0];

        // vector<ListNode*> new_lists;
        // // merge in loop
        // for (int i = 0; i < n; i += 2) {
        //     if (i + 1 < n) {
        //         new_lists.push_back(
        //             mergeTwoLists(lists[i], lists[i + 1])
        //         );
        //     } else {
        //         new_lists.push_back(lists[i]);
        //     }
        // }

        // self-recursive        
        // return mergeKLists(new_lists);

        // recursive conquer
        return conquer(lists, 0, n - 1);
    }
};

// TODO: use priority queue

// @lc code=end

