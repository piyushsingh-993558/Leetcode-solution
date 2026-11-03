class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_element=INT_MIN;
    for(int i=0;i<nums.size();i++){
     max_element=max(max_element,nums[i]);

    } 
    int ans=0;
    for(int i=0;i<nums.size();i++){
    ans+=max_element-nums[i];

    }   
    return ans;
    }
};