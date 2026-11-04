
class Solution {
public:

    long long f(vector<long long>& store_min_oper, int i, int k, int x,
                vector<vector<long long>>& dp) {

        if(k == 0) return 0;

        if(i >= store_min_oper.size()) return 1e18;

        if(dp[i][k] != -1) return dp[i][k];

        long long take = store_min_oper[i] +
                         f(store_min_oper, i + x, k - 1, x, dp);

        long long not_take =
                         f(store_min_oper, i + 1, k, x, dp);

        return dp[i][k] = min(take, not_take);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        vector<long long> minOpsSubarray(n - x + 1);

        int i = 0, j = 0;

        while(j < n) {

            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            }
            else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

           
            if(!left.empty() && !right.empty()) {

                int maxLeft = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {

                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            if(j - i + 1 == x) {

                long long median = *left.rbegin();

                long long leftSize = left.size();
                long long rightSize = right.size();

                minOpsSubarray[i] =
                    (leftSize * median - leftSum) +
                    (rightSum - rightSize * median);

                if(left.find(nums[i]) != left.end()) {

                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];

                }
                else {

                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }

                i++;

                
                if(left.size() < right.size()) {

                    auto it = right.begin();

                    left.insert(*it);
                    leftSum += *it;

                    rightSum -= *it;
                    right.erase(it);
                } 
            }

            j++; 
        }

        int m = minOpsSubarray.size();

        vector<vector<long long>> dp(
            m + 1, vector<long long>(k + 1, -1)
        );

        return f(minOpsSubarray, 0, k, x, dp);
    }
};
