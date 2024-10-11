#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void radixSort(vector<int>& nums){
        if(nums.size() < 2) return;
        radixSort(nums, 0, nums.size()-1, maxDigit(nums));    
    }

    int maxDigit(vector<int>& nums){
        int maxNum = *max_element(nums.begin(), nums.end());
        int digit = 1;
        while(maxNum /= 10) digit++;
        return digit;
    }

    int getDigit(int num, int digit){
        for(int i = 0; i < digit - 1; i++) num /= 10;
        return num % 10;
    }

    void radixSort(vector<int>& nums, int l, int r, int digit){
        const int radix = 10;
        vector<int> bucket(r-l+1, 0);
        for(int d = 1; d <= digit; d++){
            vector<int> count(radix, 0);
            for(int i = l; i <= r; i++) count[getDigit(nums[i], d)]++;
            for(int i = 1; i < radix; i++) count[i] += count[i-1];
            for(int i = r; i >= l; i--) bucket[--count[getDigit(nums[i], d)]] = nums[i];
            for(int i = l; i <= r; i++) nums[i] = bucket[i-l];
        }
    }
};

int gdx(int num, int dig, int rdx){
    return (num/(int)pow(rdx, dig-1))%10;
}

void RadixSort(vector<int> &nums){
    const int radix = 10;
    int max_val = *max_element(nums.begin(), nums.end());
    int digits = 1;
    while(max_val/=radix) digits++;
    vector <int> bucket(nums.size(), 0);
    for(int d=1; d <= digits; d++){
        vector <int> count(radix, 0);
        for(int i = 0; i < nums.size(); i++) count[gdx(nums[i],d,radix)]++;
        for(int i = radix-2; i>=0; i--) count[i] += count[i+1];
        for(int i = 0; i < nums.size(); i++) bucket[nums.size()-count[gdx(nums[i],d,radix)]--] = nums[i];
        for(int i = 0; i < nums.size(); i++) nums[i] = bucket[i];
    }
}


int main(){
    Solution sol;
    vector<int> nums = {13, 17, 25, 34, 22, 55, 5, 99, 100, 221};
    // sol.radixSort(nums);
    RadixSort(nums);
    for(auto x: nums) cout << x << " ";
    return 0;
}