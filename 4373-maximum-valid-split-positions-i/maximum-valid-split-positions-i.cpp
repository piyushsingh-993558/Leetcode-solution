class Solution {
public:
    int maximum = 0;

    void f(vector<int>& gcd_left, vector<int>& gcd_right) {
        int m = gcd_left.size();
        int count = 0;

        for (int i = 0; i < m - 1; i++) {
            if (gcd_left[i] == gcd_right[i + 1]) {
                count++;
            }
        }

        maximum = max(maximum, count);
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

        
        for (int remove = 0; remove < n; remove++) {

            vector<int> take;

            for (int i = 0; i < n; i++) {
                if (i != remove) {
                    take.push_back(nums[i]);
                }
            }

            int m = take.size();

            vector<int> gcd_left(m);
            vector<int> gcd_right(m);

           
            gcd_left[0] = take[0];

            for (int i = 1; i < m; i++) {
                gcd_left[i] = gcd(gcd_left[i - 1], take[i]);
            }

          
            gcd_right[m - 1] = take[m - 1];

            for (int i = m - 2; i >= 0; i--) {
                gcd_right[i] = gcd(gcd_right[i + 1], take[i]);
            }

            f(gcd_left, gcd_right);
        }

       
        vector<int> gcd_left(n);
        vector<int> gcd_right(n);

        gcd_left[0] = nums[0];

        for (int i = 1; i < n; i++) {
            gcd_left[i] = gcd(gcd_left[i - 1], nums[i]);
        }

        gcd_right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            gcd_right[i] = gcd(gcd_right[i + 1], nums[i]);
        }

        f(gcd_left, gcd_right);

        return maximum;
    }
};