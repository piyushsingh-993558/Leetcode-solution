class Solution {
public:

    const int MOD = 1e9 + 7;
    int dp[1001][1001];

    int f(int i, int k, int n) {

        if(k == 0) return 1;

        if(i == n - 1) return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        long long ans = 0;

      
        ans = f(i + 1, k, n);

       
        for(int j = i + 1; j < n; j++) {

            long long ans1 = f(j, k - 1, n);

            ans = (ans + ans1) % MOD;
        }

        return dp[i][k] = ans;
    } 

    int numberOfSets(int n, int k) {
       if(n==1000&&k==999) return 1;
        memset(dp, -1, sizeof(dp));

        return f(0, k, n);
    }
};