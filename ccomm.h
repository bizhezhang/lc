#include<algorithm>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>

using namespace std;
/*
single list node
1.val::int
2.next::ListNode*
3.constructor::(int),(int,ListNode*)
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
binary tree node
1.val::int
2.left::TreeNode*
3.right::TreeNode*
4.constructor::(),(int),(int, TreeNode*, TreeNode*)
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


template<typename T>
ostream& operator<<(ostream& os, const std::vector<T>& obj){
    if(obj.size() < 1) {os<<"Empty!";return os;}
    os << "[";
    int member_type = 0;
    if(typeid(obj[0]) == typeid(string)) member_type = 1;
	for (size_t i = 0; i < obj.size(); ++i)
	{
        if(member_type) os << "\"";
		os << obj[i];
        if(member_type) os << "\"";
		if (i != obj.size() - 1)
		{
			os << ",";
		}
	}
	os << "]";
	return os;
}