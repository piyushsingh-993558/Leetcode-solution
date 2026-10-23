class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        vector<int> take = nums;
        vector<pair<int,int>> swapsele;

        for (int i = 0; i < n; i++) {
            while (take[i] != i) {
                int index = take[i];

                swapsele.push_back({take[i], take[index]});

                swap(take[i], take[index]);
            }
        }

        if (swapsele.empty()) return 0;

        int ans = -1;

        for (auto &p : swapsele) {
            ans &= (p.first & p.second);
        }

        return ans;
    }
};