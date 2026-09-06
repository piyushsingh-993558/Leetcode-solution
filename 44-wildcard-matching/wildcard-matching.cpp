class Solution {
public:
bool f(string& s,string& p,vector<vector<int>>&dp){
   int n1=s.size(); 
   int n2=p.size();
   dp[n1][n2]=true;
     
 
   for(int i=0;i<n1;i++){
     dp[i][n2]=false;
   } 

   for(int j=0;j<n2;j++){
    bool flag=true;
    for(int k=j;k<n2;k++){
        if(p[k]!='*'){
         flag=false;
        }
    }
     dp[n1][j]=flag;
   }
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
         if(s[i]==p[j]||p[j]=='?'){
     dp[i][j]= dp[i+1][j+1];
   }else if(p[j]=='*'){ 
     dp[i][j]=dp[i+1][j]||dp[i][j+1];
   }else{
     dp[i][j]=false;
   }
        }
    }
     return dp[0][0];
    
    } 
    bool isMatch(string s, string p) {
        int n1=s.size(); 
        int n2=p.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
   return f(s,p,dp);
     
    }
};