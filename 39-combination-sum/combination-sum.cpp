class Solution {
public:
      set<vector<int>>st;
    void f(vector<vector<int>>&finalans,int i,vector<int>&candidates,int target,vector<int>&ans){
        int n=candidates.size();
        if(target==0){
            if(st.find(ans)==st.end()){
                finalans.push_back(ans);
                st.insert(ans);
        }
        } 
        if(i==n) return ;
      if(candidates[i]<=target){
        ans.push_back(candidates[i]);
        f(finalans,i,candidates,target-candidates[i],ans);
        ans.pop_back();
      }
      f(finalans,i+1,candidates,target,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>finalans;
        vector<int>ans;
        f(finalans,0,candidates,target,ans);
        return finalans;   
    }
};