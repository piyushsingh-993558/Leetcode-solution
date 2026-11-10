class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        costs.insert(costs.begin(), 0);

        vector<int> dp(n+1, 1e9);

       
        dp[n] = 0;

        
        for(int i = n-1; i >= 0; i--) {

            int ans1 = 1e9;
            int ans2 = 1e9;
            int ans3 = 1e9;

            if(i+1 <= n) {
                ans1 = costs[i+1] + 1 + dp[i+1];
            }

            if(i+2 <= n) {
                ans2 = costs[i+2] + 4 + dp[i+2];
            }

            if(i+3 <= n) {
                ans3 = costs[i+3] + 9 + dp[i+3];
            }

            dp[i] = min({ans1, ans2, ans3});
        }

        return dp[0];
    }
};