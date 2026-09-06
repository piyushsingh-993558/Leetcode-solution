class Solution {
public:
    int dp[501][501];
    int f(string& word1,string& word2,int i,int j){
        int n1=word1.size();
        int n2=word2.size();
        if(i>=n1&&j>=n2) return 0;
     if(i>=n1) return  n2-j;
     if(j>=n2) return n1-i;
     if(dp[i][j]!=-1) return dp[i][j];
     if(word1[i]==word2[j]){
        return dp[i][j]= f(word1,word2,i+1,j+1);
     }else{  
        return dp[i][j]= 1+min(f(word1,word2,i+1,j),f(word1,word2,i,j+1));
     }     
    }
    int minDistance(string word1, string word2) {
      memset(dp,-1,sizeof(dp));    
      return f(word1,word2,0,0);                      
    }
};