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
      if(take.size()>=3){
         bool check=true;
      int difference=take[1]-take[0];
      for(int i=2;i<take.size();i++){
        if(take[i]-take[i-1]!=difference){
              check=false;
              break;
        }
      }
      if(check) ans++;     
      }
     }
      return ans;  
    }
};