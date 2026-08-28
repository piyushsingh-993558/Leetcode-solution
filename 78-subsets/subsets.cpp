class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n=nums.size();
      int range=1<<n;
      vector<vector<int>>finalans;
    for(int mask=0;mask<range;mask++){
           vector<int>ans;
     for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            ans.push_back(nums[i]);  
        }
     }
     finalans.push_back(ans);    
    } 
     return finalans;
    }
};