class Solution {
public:

    int dp[75][75][75][4];

    int f(vector<vector<int>>& grid, int k, int i, int j, int curr_dir) {

        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || i < 0 || j >= n || j < 0 || k < 0)
            return 1e9;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (curr_dir != -1 && dp[i][j][k][curr_dir] != -1)
            return dp[i][j][k][curr_dir];

        int ans = 1e9;

      
        if (curr_dir == -1) {

            int up = grid[i][j] + f(grid, k, i - 1, j, 0);
            int down = grid[i][j] + f(grid, k, i + 1, j, 1);
            int right = grid[i][j] + f(grid, k, i, j + 1, 2);
            int left = grid[i][j] + f(grid, k, i, j - 1, 3);

            ans = min({up, down, right, left});
        }

     
        else if (curr_dir == 0) {

            int up = grid[i][j] + f(grid, k, i - 1, j, 0);
            int down = grid[i][j] + f(grid, k - 1, i + 1, j, 1);
            int right = grid[i][j] + f(grid, k - 1, i, j + 1, 2);
            int left = grid[i][j] + f(grid, k - 1, i, j - 1, 3);

            ans = min({up, down, right, left});
        }

        
        else if (curr_dir == 1) {

            int up = grid[i][j] + f(grid, k - 1, i - 1, j, 0);
            int down = grid[i][j] + f(grid, k, i + 1, j, 1);
            int right = grid[i][j] + f(grid, k - 1, i, j + 1, 2);
            int left = grid[i][j] + f(grid, k - 1, i, j - 1, 3);

            ans = min({up, down, right, left});
        }

       
        else if (curr_dir == 2) {

            int up = grid[i][j] + f(grid, k - 1, i - 1, j, 0);
            int down = grid[i][j] + f(grid, k - 1, i + 1, j, 1);
            int right = grid[i][j] + f(grid, k, i, j + 1, 2);
            int left = grid[i][j] + f(grid, k - 1, i, j - 1, 3);

            ans = min({up, down, right, left});
        }

        // Previous direction = LEFT
        else {

            int up = grid[i][j] + f(grid, k - 1, i - 1, j, 0);
            int down = grid[i][j] + f(grid, k - 1, i + 1, j, 1);
            int right = grid[i][j] + f(grid, k - 1, i, j + 1, 2);
            int left = grid[i][j] + f(grid, k, i, j - 1, 3);

            ans = min({up, down, right, left});
        }

        if (curr_dir != -1)
            dp[i][j][k][curr_dir] = ans;

        return ans;
    }

    int minCost(vector<vector<int>>& grid, int k) {

        memset(dp, -1, sizeof(dp));

        int ans = f(grid, k, 0, 0, -1);

        return ans >= 1e9 ? -1 : ans;
    }
};