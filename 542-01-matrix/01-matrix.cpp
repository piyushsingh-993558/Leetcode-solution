class Solution {
public:

    vector<pair<int,int>> dir = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> visited(
            m,
            vector<int>(n, 0)
        );

        vector<vector<int>> ans(
            m,
            vector<int>(n, 0)
        );

       
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {

                    q.push({i,j});

                    visited[i][j] = 1;

                    ans[i][j] = 0;
                }
            }
        }

        
        while(!q.empty()) {

            auto take = q.front();
            q.pop();

            int row = take.first;
            int col = take.second;

            for(int d = 0; d < 4; d++) {

                int curr_row = row + dir[d].first;
                int curr_col = col + dir[d].second;

               
                if(curr_row < 0 || curr_row >= m ||
                   curr_col < 0 || curr_col >= n) {
                    continue;
                }

              
                if(visited[curr_row][curr_col] == 1) {
                    continue;
                }

             
                visited[curr_row][curr_col] = 1;

              
                ans[curr_row][curr_col] =
                    ans[row][col] + 1;

               
                q.push({curr_row, curr_col});
            }
        }

        return ans;
    }
};