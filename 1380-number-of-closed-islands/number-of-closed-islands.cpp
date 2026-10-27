
class Solution {
public:
    vector<vector<int>> visited;

    
    bool f(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size()) {
            return false;
        }

        if (grid[row][col] == 1 || visited[row][col] == 1) {
            return true;
        }

        visited[row][col] = 1;

        bool left = f(grid, row, col - 1);
        bool right = f(grid, row, col + 1);
        bool top = f(grid, row - 1, col);
        bool down = f(grid, row + 1, col);

        return left && right && top && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        visited.assign(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (f(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
