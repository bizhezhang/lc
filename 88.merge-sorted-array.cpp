/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vit;

// @lc code=start
class Solution {
public:
    //将nums1右移后，从小到大合并；也可以不右移nums1，在数组右端，从大到小合并。
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        assert(m+n == (int)nums1.size());
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }
        
        int i = n, j = 0, k = 0;

        while (i < m + n && j < n) {
            if (nums1[i] < nums2[j])
                nums1[k++] = nums1[i++];
            else 
                nums1[k++] = nums2[j++];
        }
        // Append the remaining elements of nums1 or nums2 to the merged array.
        while (i < m + n)
            nums1[k++] = nums1[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
    //虽然能过，但逻辑有漏洞，不建议！
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     while(n > 0)
    //         nums1[m + n] = m < 1 || nums1[m - 1] < nums2[n - 1] ? nums2[--n] : nums1[--m];
    // }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    vit a = {1,2,3,0,0,0};
    vit b = {2,5,6};
    int m = 3, n = 3;
    Solution().merge(a, m, b, n);
    for(vector<int>::iterator it = a.begin(); it < a.end(); it++){
        cout<<*it<<",";
    }
    return 0;
}

/*
1 9 10
2 4 6 7 8 11
*/