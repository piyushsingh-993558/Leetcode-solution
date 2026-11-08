class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      unordered_map<int,int>mp_row;
      unordered_map<int,int>mp_col;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==1){
             mp_row[i]++;
             
          }
        }
      }
       for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
          if(grid[i][j]==1){
          mp_col[j]++;
           
          } 
        }
      } 
      int ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
            if(mp_row.find(i)!=mp_row.end()&&mp_row[i]>1){
                ans++;
            }else if(mp_col.find(j)!=mp_col.end()&&mp_col[j]>1){
                ans++;
            }   
                }
            }
        }
        
          
        
       return ans;
    }
};