class Solution {
public:
    int dp[100001];
    int f(int n){
         if(n==0) return 0;
         if(dp[n]!=-1) return dp[n];
         int ans=INT_MAX;
        for(int i=1;i<=n;i++){
         long long  sum=i*(i+1)/2;
        if(sum<=n){  
          ans=min(ans,i+1+f(n-sum));    
          }else{
            break;
          } 
        }  
        return dp[n]= ans;
    }   
    int minDays(int n) {
       memset(dp,-1,sizeof(dp));  
       return f(n)-1;   
    }
};