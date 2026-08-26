class Solution {
public:
   unordered_set<int>st;
    void f(vector<int>&nums,vector<vector<int>>&finalans,vector<int>&ans,int i){
        int n=nums.size();
        if(i==n){
            finalans.push_back(ans);
            return; 
        }  
        for(int j=0;j<n;j++){
            if(st.find(j)==st.end()){ 
           ans.push_back(nums[j]);
           st.insert(j);
           f(nums,finalans,ans,i+1);  
           ans.pop_back();
          st.erase(j); 
            } 
                
        }  
    }
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>>finalans;
    vector<int>ans;
    f(nums,finalans,ans,0);
    return finalans;
    }
};