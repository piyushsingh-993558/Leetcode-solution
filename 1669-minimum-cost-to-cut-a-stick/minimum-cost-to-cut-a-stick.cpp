
class Solution {
public:
    int dp[101][101];
    int f(vector<int>& cuts, int i, int j) {

      
        if (i > j)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;

      
        for (int k = i; k <= j; k++) {

            int cost = cuts[j + 1] - cuts[i - 1]
                     + f(cuts, i, k - 1)
                     + f(cuts, k + 1, j);

            mini = min(mini, cost);
        }

        return dp[i][j]= mini;
    }

    int minCost(int n, vector<int>& cuts) {

        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

      
        sort(cuts.begin(), cuts.end());

      
        int m = cuts.size();

    
        return f(cuts, 1, m - 2);
    }
};

