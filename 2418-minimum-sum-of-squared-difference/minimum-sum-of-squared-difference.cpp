
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long total_operation = 1LL * k1 + k2;

        int maximum = 0;
        vector<int> take;

        for (int i = 0; i < n; i++) {
            int difference = abs(nums1[i] - nums2[i]);
            maximum = max(maximum, difference);
            take.push_back(difference);
        }

        vector<int> store(maximum + 1, 0);

        long long total_diff = 0;

        for (int i = 0; i < n; i++) {
            store[take[i]]++;
            total_diff += take[i];
        }

        if (total_operation >= total_diff) {
            return 0;
        }

        for (int i = maximum; i > 0 && total_operation > 0; i--) {
            int frequency = store[i];

            if (frequency == 0) {
                continue;
            }

            long long reduce = min(total_operation, 1LL * frequency);

            store[i] -= reduce;
            store[i - 1] += reduce;

            total_operation -= reduce;
        }

        long long answer = 0;

        for (int i = 0; i <= maximum; i++) {
            answer += 1LL * i * i * store[i];
        }

        return answer;
    }
};
