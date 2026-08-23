class Solution {
public:

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {

            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;

        int distinct = 0;
        int ans = 0;

        while (j < n) {
      
            vector<int> factors = getPrimeFactors(nums[j]);

            for (int p : factors) {

                if (freq[p] == 0) {
                    distinct++;
                }

                freq[p]++;
            }

            
            while (distinct > k) {

                vector<int> leftFactors = getPrimeFactors(nums[i]);

                for (int p : leftFactors) {

                    freq[p]--;

                    if (freq[p] == 0) {
                        distinct--;
                    }
                }

                i++;
            }

    
            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};