class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
      unordered_map<int,vector<int>>mp;
      for(int i=0;i<nums.size();i++){
        mp[nums[i]].push_back(i);
      }
     int ans=0;
     for(auto &ele:mp){
    vector<int>take=ele.second;
      if(take.size()==3){
       if(take[2]-take[1]==take[1]-take[0]){
        ans++;
       }   
      }
     }
      return ans;  
    }
};