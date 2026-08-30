class Solution {
public:
     int dp[13][10001];
    int f(vector<int>&coins,int i ,int amount){
        if(amount==0) return 0;
        if(amount<0) return 1e9;
        if(i>=coins.size()) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=1+f(coins,i,amount-coins[i]);
        int not_take=f(coins,i+1,amount);
        return dp[i][amount]= min(take,not_take); 
    }
    int coinChange(vector<int>& coins, int amount) {
     memset(dp,-1,sizeof(dp));
    int ans=f(coins,0,amount);
    return (ans>=1e9)?-1:ans;      
    }
};