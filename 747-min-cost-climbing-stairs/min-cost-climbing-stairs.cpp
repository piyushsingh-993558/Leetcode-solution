class Solution {
public:
   
    //  int dp[1002];
    // int f(vector<int>&cost,int i){
    //      dp[n]=0;
    //      dp[n+1]=1e9;    
    //     // int n=cost.size();
    //     // if(i==n) return 0;
    //     // if(i>n) return 1e9;
    //     // if(dp[i]!=-1) return dp[i];
    //     // int ans1=cost[i]+f(cost,i+1);
    //     // int ans2=cost[i]+f(cost,i+2);
    //     // return  dp[i]=min(ans1,ans2);
    //     for(int i=n-1;i>=0;i--){
    //       dp[i]=cost[i]+f(dp[i+1],dp[i+2]);
    //     } 
    //     return min(dp[0],dp[1]);
    // }    
    int minCostClimbingStairs(vector<int>& cost) {
        // memset(dp,-1,sizeof(dp));
        int n=cost.size();
    //    int finalans1=f(cost,0);
    //    int finalans2=f(cost,1);
      
    //    return min(finalans1,finalans2);
      vector<int>dp(n+2,0);
    //  dp[n]=0;
         dp[n+1]=1e9;
       for(int i=n-1;i>=0;i--){
          dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }  
        return min(dp[0],dp[1]);      
        
     }
};