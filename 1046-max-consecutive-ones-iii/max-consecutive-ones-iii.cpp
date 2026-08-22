class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int count_zero = 0;
        int max_length = 0;

        while (j < n) {

            if (nums[j] == 0) {
                count_zero++;
            }

            while (count_zero > k) {
                if (nums[i] == 0) {
                    count_zero--;
                }
                i++;
            }

            max_length = max(max_length, j - i + 1);

            j++;
        }

        return max_length;
    }
};