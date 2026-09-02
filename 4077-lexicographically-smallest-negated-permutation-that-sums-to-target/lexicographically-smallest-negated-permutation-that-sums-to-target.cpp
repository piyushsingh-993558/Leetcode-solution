class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {

        long long S = 1LL * n * (n + 1) / 2;

        if (target < -S || target > S)
            return {};

        long long need = S - target;

        if (need % 2 != 0)
            return {};

        long long negSum = need / 2;

        vector<int> ans;

        for (int x = n; x >= 1; x--) {

            if (x <= negSum) {
                ans.push_back(-x);
                negSum -= x;
            }
            else {
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};