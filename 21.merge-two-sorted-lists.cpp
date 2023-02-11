/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *preHead = new ListNode(-1);
        ListNode *pr = preHead, *p1 = list1, *p2 = list2;
        while(p1 && p2){
            if(p1->val < p2->val){
                pr->next = p1;
                p1 = p1->next;
            }else{
                pr->next = p2;
                p2 = p2->next;
            }
            pr = pr->next;
        }
        pr->next = p1 ? p1 : p2;
        
        return preHead->next;
    }
};
// @lc code=end

