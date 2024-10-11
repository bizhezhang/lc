#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapSort(vector<int>& nums){
        if(nums.size() < 2) return;
        // for(int i = 0; i < nums.size(); i++){
        //     heapInsert(nums, i);
        // }
        heapSize = nums.size();
        for(int i = (nums.size()-2)/2; i >= 0; i--) heapify(nums, i);
        while(heapSize > 0){
            swap(nums[0], nums[--heapSize]);
            heapify(nums, 0);
        }
    }

    int heapSize = 0;
    void heapInsert(vector<int>& nums, int index){
        while(nums[index] > nums[(index-1)/2]){
            swap(nums[index], nums[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void heapify(vector<int>& nums, int index){
        int left = 2 * index + 1;
        while(left < heapSize){
            int largest = left + 1 < heapSize && nums[left + 1] > nums[left] ? left + 1 : left;
            largest = nums[largest] > nums[index] ? largest : index;
            if(largest == index) break;
            swap(nums[largest], nums[index]);
            index = largest;
            left = 2 * index + 1;
        }
    }
};


class Heap{
public:
    vector<int> nums;
    int heapSize;
    Heap(vector<int>& nums){
        heapSize = nums.size();
        this->nums = nums;
    }

    void heapSort(){
        for(int i = (heapSize-2)/2; i >= 0; i--) heapify(i);
        while(heapSize > 0){
            swap(nums[0], nums[--heapSize]);
            heapify(0);
        }
    }

    void printHeap(){
        for(int i = 0; i < nums.size(); i++) cout<<nums[i]<<" ";
    }

    void heapify(int index){
        int left = 2 * index + 1;
        while(left < heapSize){
            int largest = left + 1 < heapSize && nums[left+1] > nums[left] ? left + 1 : left;
            largest = nums[largest] > nums[index] ? largest : index;
            if(largest == index) return;
            swap(nums[index], nums[largest]);
            index = largest;
            left = 2 * index + 1;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, 2, 1, 5, 6, 1, 3, 4, 4};
    // sol.heapSort(nums);
    // for(auto x: nums) cout << x << " ";

    Heap heap_test(nums);
    heap_test.heapSort();
    heap_test.printHeap();
    return 0;
}
