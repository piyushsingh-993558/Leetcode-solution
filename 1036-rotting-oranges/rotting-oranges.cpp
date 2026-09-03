class Solution {
public:

    vector<pair<int,int>> dir = {
        {-1,0},   
        {1,0},    
        {0,-1},   
        {0,1}     
    };

    int bfs(
        vector<vector<int>>& grid,
        queue<pair<int,int>>& q,
        vector<vector<int>>& visited
    ) {

        int n = grid.size();
        int m = grid[0].size();

        int minutes = 0;

        while (!q.empty()) {

          
            int size = q.size();

            bool changed = false;

          
            for (int i = 0; i < size; i++) {

                pair<int,int> take = q.front();
                q.pop();

                int row = take.first;
                int col = take.second;

               
                for (int d = 0; d < 4; d++) {

                    int curr_row = row + dir[d].first;
                    int curr_col = col + dir[d].second;


                    if (curr_row < 0 || curr_row >= n ||
                        curr_col < 0 || curr_col >= m) {
                        continue;
                    }

                  
                    if (grid[curr_row][curr_col] != 1) {
                        continue;
                    }

                 
                    if (visited[curr_row][curr_col] == 1) {
                        continue;
                    }

                 
                    visited[curr_row][curr_col] = 1;

                    
                    q.push({curr_row, curr_col});

                    changed = true;
                }
            }

            
            if (changed) {
                minutes++;
            }
        }

        return minutes;
    }


    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(
            n,
            vector<int>(m, 0)
        );

        queue<pair<int,int>> q;

        
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {

                    q.push({i,j});

                    visited[i][j] = 1;
                }

               
            }
        }

     
        int ans = bfs(grid, q, visited);

      
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 &&
                    visited[i][j] == 0) {

                    return -1;
                }
            }
        }

        return ans;
    }
};