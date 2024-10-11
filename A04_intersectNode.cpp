#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

class Solution {
public:
    Node* getIntersectionNode(Node* headA, Node* headB){
        if(!headA || !headB) return nullptr;
        Node* loopA = getLoop(headA);
        Node* loopB = getLoop(headB);
        if(!loopA && !loopB) return getNoLoop(headA, headB);
        else if(loopA && loopB) return getBothLoop(headA, headB, loopA, loopB);
        else return nullptr;
    }

    Node* getLoop(Node* head){
        if(!head||!head->next||!head->next->next) return nullptr;
        Node* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr;
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    Node* getNoLoop(Node* headA, Node* headB){
        Node* curA = headA, *curB = headB;
        int diff = 0;
        while(curA->next) curA = curA->next, diff++;
        while(curB->next) curB = curB->next, diff--;
        if(curA != curB) return nullptr;
        curA = diff > 0 ? headA : headB;
        curB = curA == headA ? headB : headA;
        diff = diff > 0 ? diff : -diff;
        while(diff--) curA = curA->next;
        while(curA != curB) curA = curA->next, curB = curB->next;
        return curA;
    }

    Node* getBothLoop(Node* headA, Node* headB, Node* loopA, Node* loopB){
        Node* curA = headA, *curB = headB;
        if(loopA == loopB){
            Node *loopnext = loopA->next;
            loopA->next = nullptr;
            Node* res = getNoLoop(headA, headB);
            loopA->next = loopnext;
            return res;
        }else{
            Node *cur = loopA->next;
            while(cur != loopA){
                if(cur == loopB) return loopA;
                cur = cur->next;
            }
            return nullptr;
        }
    }
};


int main(){
    Solution sol;
    Node* X = new Node(13);
    Node* loopNode = new Node(10, new Node(11, new Node(12, X)));
    X->next = loopNode;
    Node* commNode = new Node(4, new Node(5, new Node(6)));
    Node* headA = new Node(1, new Node(2, new Node(3, X)));
    Node* headB = new Node(7, new Node(8, new Node(9, loopNode->next)));
    Node* res = sol.getIntersectionNode(headA, headB);
    if(res) cout << res->val << endl;
    else cout << "No intersection" << endl;
    return 0;
}