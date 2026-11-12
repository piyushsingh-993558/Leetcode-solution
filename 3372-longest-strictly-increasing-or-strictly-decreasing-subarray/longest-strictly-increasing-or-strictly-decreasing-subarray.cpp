
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        int i = 0;
        int j = 1;
        int previous_element = nums[0];
        int max_inc_count = INT_MIN;

       
        while(j < n) {
            if(nums[j] > previous_element) {
                previous_element = nums[j];
                j++;
            }
            else {
                max_inc_count = max(max_inc_count, j-i);
                i = j;
                previous_element = nums[i];
                j++;
            }
        }

        max_inc_count = max(max_inc_count, j-i);

     
        i = 0;
        j = 1;
        previous_element = nums[0];

        int max_desc_count = INT_MIN;

       
        while(j < n) {
            if(nums[j] < previous_element) {
                previous_element = nums[j];
                j++;
            }
            else {
                max_desc_count = max(max_desc_count, j-i);
                i = j;
                previous_element = nums[i];
                j++;
            }
        }

        max_desc_count = max(max_desc_count, j-i);

        return max(max_desc_count, max_inc_count);
    }
};
