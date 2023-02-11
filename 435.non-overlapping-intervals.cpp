/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include "ccomm.h"

// @lc code=start
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int removed = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                ++removed;
            } else {
                prev = intervals[i][1];
            }
        }
        return removed;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    vector<vector<int>> input = {{1, 2}, {2, 4}, {1, 3}, {3, 5}, {4, 5}};
    int n = Solution().eraseOverlapIntervals(input);
    cout << input << endl;
    cout << n << endl;
    return 0;
}