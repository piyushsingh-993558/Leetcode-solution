class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
    unordered_set<int>st;
    for(auto ele:nums){
        st.insert(ele);
    } 
      unordered_map<int,vector<int>>mp;
    for(auto ele:st){
        int left=-1;
        int right=-1;
        int count=0;
        for(int i=0;i<n;i++){
      if(nums[i]==ele){
        left=i;
          break;
        } 
        }
        for(int i=0;i<n;i++){
            if(nums[i]==ele) count++;
        } 
        for(int i=n-1;i>=0;i--){
      if(nums[i]==ele){
         right=i;
         break;
      }
      
        }
    //  mp[ele].push_back({left,right,count});
    mp[ele].push_back(left);
    mp[ele].push_back(right);
     mp[ele].push_back(count);
    }  
      int total_ans=0; 
    for(auto ele:mp){
    vector<int>take=ele.second;
    if((take[1]-take[0]+1)==take[2]){
        total_ans++;
    }
    }
     return total_ans;
               
    }
};