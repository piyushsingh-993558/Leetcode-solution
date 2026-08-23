class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int first = lower;
        vector<vector<int>> finalans;

        for(int i = 0; i < n; i++) {

            if(nums[i] >= first && nums[i] <= upper) {

             
                if(first <= nums[i] - 1) {
                    finalans.push_back({first, nums[i] - 1});
                }

                first = nums[i] + 1;
            }
        }

       
        if(first <= upper) {
            finalans.push_back({first, upper});
        }

        return finalans;
    }
};