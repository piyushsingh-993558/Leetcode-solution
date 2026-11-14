class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minimum = INT_MAX;

        int i = 0;
        int j = 0;
        int current_sum = 0;

        while (i < n) {

            j = i;
            current_sum = 0;

            while (j < n && j - i + 1 <= r) {

                current_sum += nums[j];

                if (j - i + 1 >= l && current_sum > 0) {
                    minimum = min(minimum, current_sum);
                }
    
                j++;
            } 

            i++;
        }

        return minimum == INT_MAX ? -1 : minimum;
    }
};