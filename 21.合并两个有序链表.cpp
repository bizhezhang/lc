/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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

void prtn(struct ListNode *list){
    struct ListNode *p = list;
    while (p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    Solution sl;
    struct ListNode l1;
    l1.val = 1;
    struct ListNode l12;
    l12.val = 2;l1.next = &l12;
    struct ListNode l13;
    l13.val = 4;l12.next = &l13;
    l13.next = NULL;
    struct ListNode l2;
    l2.val = 0;
    struct ListNode l22;
    l22.val = 3;l2.next = &l22;
    struct ListNode l23;
    l23.val = 5;l22.next = &l23;
    l23.next = NULL;
    prtn(&l1);
    prtn(&l2);
    struct ListNode *l3 = sl.mergeTwoLists(&l1, &l2);
    
    
    prtn(l3);
    return 0;
}