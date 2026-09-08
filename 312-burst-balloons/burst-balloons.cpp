class Solution {
public: 
    int dp[301][301];
    int f(vector<int>&nums,int i,int j){
      if(j<i) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      int maximum=-1e9;
      for(int k=i;k<=j;k++){
       int cost=nums[k]*nums[j+1]*nums[i-1]+f(nums,i,k-1)+f(nums,k+1,j);
       maximum=max(maximum,cost);
      }
       return dp[i][j]= maximum;
    }  
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
      nums.push_back(1);
      nums.insert(nums.begin(),1);
      int n=nums.size();
      return f(nums,1,n-2);          
    }
};