#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums){
        srand((unsigned int)time(NULL));
        if(nums.size() < 2) return;
        quick_sort_func(nums, 0, nums.size()-1);
    }

    tuple<int, int> partition(vector<int>& nums, int l, int r){
        int pivot = rand() % (r-l+1) + l;
        swap(nums[pivot], nums[r]);
        int i = l-1, j = r;
        for(int k = l; k < j; k++){
            if(nums[k] < nums[r])
                swap(nums[++i], nums[k]);
            else if(nums[k] > nums[r])
                swap(nums[--j], nums[k--]);
        }
        swap(nums[j], nums[r]);
        return {i+1, j};
    }

    void quick_sort_func(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int m1, m2;tie(m1, m2) = partition(nums, l, r);
        quick_sort_func(nums, l, m1-1);
        quick_sort_func(nums, m2+1, r);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, 2, 1, 5, 6, 1, 3, 4, 4};
    sol.quickSort(nums);
    for(auto x: nums) cout << x << " ";
    return 0;
}