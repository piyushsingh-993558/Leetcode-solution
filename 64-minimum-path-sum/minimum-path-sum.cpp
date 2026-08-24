class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
       
        vector<vector<int>> dp(m, vector<int>(n, 0));

        
        dp[m-1][n-1] = grid[m-1][n-1];

      
        for(int i = m-1; i >= 0; i--) {

           
            for(int j = n-1; j >= 0; j--) {

                
                if(i == m-1 && j == n-1)
                    continue;

                int ans1 = INT_MAX;
                int ans2 = INT_MAX;

               
                if(i+1 < m) {
                    ans1 = grid[i][j]+dp[i+1][j];
                }

                
                if(j+1 < n) {
                    ans2 = grid[i][j]+dp[i][j+1];
                }

                dp[i][j] =  min(ans1, ans2);
            }
        }

        return dp[0][0];
    }
};