#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<long long, int>,
    null_type,
    less<pair<long long, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> pbds;

class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {

        int n = nums.size();

        // Total number of subarrays
        long long total = 1LL * n * (n + 1) / 2;

        // If k = 0:
        // abs(sum - goal) >= 0 is always true.
        if(k == 0)
            return total;

        pbds st;

        long long prefix = 0;
        long long good = 0;

        // prefix sum 0 before starting
        st.insert({0, 0});

        for(int i = 0; i < n; i++) {

            prefix += nums[i];

            /*
                We want NON-DISTANT subarrays:

                abs(sum - goal) < k

                => -k < sum - goal < k

                => goal-k < sum < goal+k

                sum = prefix - previousPrefix

                => prefix - goal - k < previousPrefix
                                      < prefix - goal + k

                Therefore:

                L < previousPrefix < R
            */

            long long L = prefix - goal - k;
            long long R = prefix - goal + k;

            /*
                order_of_key({R, -1})
                = number of prefix pairs whose value < R

                order_of_key({L, INT_MAX})
                = number of prefix pairs whose value <= L

                Difference:
                number of prefix values satisfying L < value < R
            */

            long long cntR = st.order_of_key({R, -1});
            long long cntL = st.order_of_key({L, INT_MAX});

            good += cntR - cntL;

            // Insert current prefix
            st.insert({prefix, i + 1});
        }

        // Distant = total - non-distant
        return total - good;
    }
};