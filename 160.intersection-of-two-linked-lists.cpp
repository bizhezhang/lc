/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flag = 0;
        unordered_map<ListNode*, int> hashA;
        unordered_map<ListNode*, int> hashB;
        while(headA || headB){
            if(headA) hashA[headA] = 1;
            if(headB) hashB[headB] = 1;
            if(hashA.find(headB) != hashA.end()){
                flag = 1;
                return headB;
            }else if(hashB.find(headA) != hashB.end()){
                flag = 1;
                return headA;
            }
            if(headA) headA = headA->next;
            if(headB) headB = headB->next;
        }
        if(!flag){
            return nullptr;
        }
        return nullptr;

    }
};
// @lc code=end

