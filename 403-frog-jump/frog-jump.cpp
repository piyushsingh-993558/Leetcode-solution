class Solution {
public:

    bool canCross(vector<int>& stones) {

        int n = stones.size();

        if (stones[1] != 1)
            return false;

        unordered_map<int, int> posToIndex;

        // stone position -> index
        for (int i = 0; i < n; i++) {
            posToIndex[stones[i]] = i;
        }

        // dp[idx][k]
        // Can we reach the last stone from idx
        // when previous jump was k?
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case
        // Last stone is already reached
        for (int k = 0; k <= n; k++) {
            dp[n - 1][k] = 1;
        }

        // Fill from right to left
        for (int idx = n - 2; idx >= 1; idx--) {

            int pos = stones[idx];

            // k can go only up to n-1
            for (int k = 1; k < n; k++) {

                bool ans1 = false;
                bool ans2 = false;
                bool ans3 = false;

                // k - 1 jump
                if (k - 1 > 0 &&
                    posToIndex.count(pos + k - 1)) {

                    int nextIdx = posToIndex[pos + k - 1];

                    ans1 = dp[nextIdx][k - 1];
                }

                // k jump
                if (posToIndex.count(pos + k)) {

                    int nextIdx = posToIndex[pos + k];

                    ans2 = dp[nextIdx][k];
                }

                // k + 1 jump
                if (posToIndex.count(pos + k + 1)) {

                    int nextIdx = posToIndex[pos + k + 1];

                    ans3 = dp[nextIdx][k + 1];
                }

                bool ans = ans1 || ans2 || ans3;

                dp[idx][k] = ans;
            }
        }

        return dp[1][1];
    }
};