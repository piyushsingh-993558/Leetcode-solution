class Solution {
public:

    int f(vector<int>& prefix, int target,
          vector<vector<int>>& dp,
          unordered_map<int,int>& mp,
          int i, int k) {

        int n = prefix.size();

        if(k == 0)
            return 0;

        if(i >= n)
            return 1e9;

        if(dp[i][k] != -1)
            return dp[i][k];

       
        int not_take = f(prefix, target, dp, mp, i + 1, k);

        int take = 1e9;

        int required;

        if(i == 0)
            required = target;
        else
            required = prefix[i - 1] + target;

       
        if(mp.find(required) != mp.end()) {

            int j = mp[required];

            if(j >= i) {

                take = (j - i + 1)
                     + f(prefix, target, dp, mp, j + 1, k - 1);
            }
        }

        return dp[i][k] = min(take, not_take);
    }


    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> prefix(n);

        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[prefix[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(3, -1));

        int ans = f(prefix, target, dp, mp, 0, 2);

        return (ans >= 1e9) ? -1 : ans;
    }
};