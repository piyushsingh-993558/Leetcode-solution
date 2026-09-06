class Solution {
public:

    int f(string& s, int i, int j, vector<vector<int>>& dp) {

        int n = s.size();

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = 0;
            }
        }

       
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
               if(i>j) continue;
                if (i == j) {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    int longestPalindromeSubseq(string s) {

        int n = s.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(n + 1, -1));

        return f(s, 0, n - 1, dp);
    }
};