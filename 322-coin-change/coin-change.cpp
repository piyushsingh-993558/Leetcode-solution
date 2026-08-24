class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int m = 1e4;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // i == n
        // amount > 0 -> impossible
        for(int i = 0; i <= amount; i++) {
            dp[n][i] = 1e9;
        }

        // amount == 0 -> 0 coins
        dp[n][0] = 0;

        for(int i = n - 1; i >= 0; i--) {

            for(int j = 0; j <= amount; j++) {

                int ans1 = 1e9;

                // Take coin
                if(coins[i] <= j) {
                    ans1 = min(ans1,
                               1 + dp[i][j - coins[i]]);
                }

                // Don't take coin
                ans1 = min(ans1, dp[i + 1][j]);

                dp[i][j] = ans1;
            }
        }

        if(dp[0][amount] == 1e9)
            return -1;

        return dp[0][amount];
    }
};