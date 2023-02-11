/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // int fib[46] = {1,1,2,3,5,8,13,21,34,55,89,144,
        // 233,377,610,987,1597,2584,4181,6765,10946,17711,
        // 28657,46368,75025,121393,196418,317811,514229,
        // 832040,1346269,2178309,3524578,5702887,9227465,
        // 14930352,24157817,39088169,63245986,102334155,
        // 165580141,267914296,433494437,701408733,
        // 1134903170,1836311903};
        int fib[46];
        fib[1] = fib[0] = 1;
        for(int i = 2; i < n+1; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};
// @lc code=ends
