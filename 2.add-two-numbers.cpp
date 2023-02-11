/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include "ccomm.h"

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1 && l2) return l2;
        if(l1 && !l2) return l1;

        int a = l1->val + l2->val;
        auto p = new ListNode(a % 10);
        p->next = addTwoNumbers(l1->next, l2->next);
        if(a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
        return p;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *l3 = Solution().addTwoNumbers(l1,l2);
    while(l3){
        cout<<l3->val;
        l3 = l3->next;
    }
    return 0;
}
