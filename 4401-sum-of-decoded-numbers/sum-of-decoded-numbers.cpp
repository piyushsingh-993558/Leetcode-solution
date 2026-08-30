class Solution {
public:

    const long long MOD = 1e9 + 7;

    long long myPOW(long long x, long long y) {

        long long ans = 1;

        while(y > 0) {

            if(y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;

            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {

        int n = nums.size();

        long long answer = 0;

        for(int i = 0; i < n; i++) {

            int width = nums[i] % 10;

            long long di = nums[i] / 10;

            string s = to_string(di);

            int len = s.size();

            int x = 0;
            int y = 0;

            int j = 0;

            while(j < len) {

                if(width != 0) {

                    x = x * 10 + (s[j] - '0');

                    width--;
                }
                else {

                    y = y * 10 + (s[j] - '0');
                }

                j++;
            }

            long long decoded_value = myPOW(x, y);

            answer = (answer + decoded_value) % MOD;
        }

        return answer;
    }
};