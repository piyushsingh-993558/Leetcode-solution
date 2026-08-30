#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
private:
    // dp[i][target] stores the minimum operations needed from index i to reach target sum
    int dp[105][5005];
    const int INF = 1e9;

    int solve(vector<int>& nums, int i, int target) {
        // Base Case 1: Target sum achieved
        if (target == 0) return 0;
        
        // Base Case 2: Out of elements
        if (i == nums.size()) return INF;

        // Base Case 3: Return memoized result FIRST before making any recursive calls
        if (dp[i][target] != -1) return dp[i][target];

        // OPTION 0: Do NOT include nums[i] in the subset
        int ans = solve(nums, i + 1, target);

        // OPTION 1: Double nums[i] zero or more times (0, 1, 2, ... operations)
        long long val = nums[i];
        int ops = 0;
        while (val <= target) {
            int next = solve(nums, i + 1, target - val);
            if (next != INF) {
                ans = min(ans, ops + next);
            }
            val *= 2;
            ops++;
        }

        // OPTION 2: Halve nums[i] one or more times (1, 2, 3, ... operations)
        val = nums[i] / 2;
        ops = 1; 
        while (val > 0) {
            if (val <= target) {
                int next = solve(nums, i + 1, target - val);
                if (next != INF) {
                    ans = min(ans, ops + next);
                }
            }
            val /= 2;
            ops++;
        }

        return dp[i][target] = ans;
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0, sum);
        return ans >= INF ? -1 : ans;
    }
};