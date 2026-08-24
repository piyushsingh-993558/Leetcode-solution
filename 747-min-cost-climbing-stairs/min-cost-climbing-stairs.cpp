class Solution {
public:

     int dp[1002];
    int f(vector<int>&cost,int i){
        int n=cost.size();
        if(i==n) return 0;
        if(i>n) return 1e9;
        if(dp[i]!=-1) return dp[i];
        int ans1=cost[i]+f(cost,i+1);
        int ans2=cost[i]+f(cost,i+2);
        return  dp[i]=min(ans1,ans2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
       int finalans1=f(cost,0);
       int finalans2=f(cost,1);
       
       return min(finalans1,finalans2);  

     }
};