class Solution {
public:
     int n;
     int m;
    void dfs(vector<vector<char>>&grid,int row,int col,vector<vector<int>>&visited){
    if(row<0||row>=n||col>=m||col<0||visited[row][col]==1||grid[row][col]=='0') return;
    visited[row][col]=1;
    dfs(grid,row+1,col,visited);
    dfs(grid,row-1,col,visited);
    dfs(grid,row,col+1,visited);
    dfs(grid,row,col-1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
         int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]=='1'){
                 ans++;
                 dfs(grid,i,j,visited);
                } 
            }
        }
         return ans;
         }
};