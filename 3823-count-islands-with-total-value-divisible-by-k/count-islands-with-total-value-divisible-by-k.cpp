
class Solution {
public:
    vector<vector<int>> visited;

    long long f(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size())
            return 0;

        if (grid[row][col] == 0 || visited[row][col] == 1)
            return 0;

        visited[row][col] = 1;

        long long left = f(grid, row, col - 1);
        long long right = f(grid, row, col + 1);
        long long top = f(grid, row - 1, col);
        long long down = f(grid, row + 1, col);

        return (long long)grid[row][col] + left + right + top + down;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int finalans = 0;
        visited.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long ans = f(grid, i, j);

                    if (ans % k == 0)
                        finalans++;
                }
            }
        }

        return finalans;
    }
};
