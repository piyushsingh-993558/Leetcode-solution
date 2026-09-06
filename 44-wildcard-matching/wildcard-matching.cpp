class Solution {
public:
bool f(string& s,string& p,int i,int j,vector<vector<int>>&dp){
   int n1=s.size(); 
   int n2=p.size();
   if(i==n1&&j==n2) return true;
   if(i<n1&&j==n2) return false; 
   if(i>=n1&&j<n2){
    for(int k=j;k<n2;k++){
        if(p[k]!='*') return false;
    }
     return true;
   } 
   if(dp[i][j]!=-1) return dp[i][j];
   if(s[i]==p[j]||p[j]=='?'){
    return dp[i][j]= f(s,p,i+1,j+1,dp);
   }else if(p[j]=='*'){
    return dp[i][j]=f(s,p,i+1,j,dp)||f(s,p,i,j+1,dp);
   }else{
    return dp[i][j]=false;
   }
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
   return f(s,p,0,0,dp);
    
    }
};