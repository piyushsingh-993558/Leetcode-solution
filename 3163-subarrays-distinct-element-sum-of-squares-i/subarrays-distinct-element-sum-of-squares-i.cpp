class Solution {
public:
    int sumCounts(vector<int>& nums) {
      int n=nums.size();
      unordered_set<int>st;
     int ans=0;
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        st.insert(nums[j]);
        int l=st.size();
      ans+=l*l;
      }
       st.clear();     
    }
     return ans;    
    }
    
};