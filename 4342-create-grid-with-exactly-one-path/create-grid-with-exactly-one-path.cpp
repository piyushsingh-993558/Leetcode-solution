class Solution {
public:
    vector<string> createGrid(int m, int n){
        vector<vector<char>>grid(m,vector<char>(n,'#'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(i==0){
            grid[i][j]='.';    
            }  
                if(j==n-1){
                 grid[i][j]='.';    
                }
            }
        } 
        
  vector<string>ans;
  for(int i=0;i<m;i++){
      string create="";
  for(int j=0;j<n;j++){
    create+=grid[i][j];    
  } 
      ans.push_back(create);
  }    
      return ans;     
    }
};