class Solution {
public:

    int dp[2001][2001];
    vector<vector<bool>> isPalindrome;
    int k;

    int f(string& s, int i, int j) {

        int n = s.size();

        if (j >= n || i >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

      
        if (isPalindrome[i][j]) {

         
            int take = 1 + f(s, j+1, j + k);

            
            int grow = f(s, i, j + 1);

          
            int slide = f(s, i + 1, j + 1);

            ans = max({take, grow, slide});
        }
        else {

           
            int grow = f(s, i, j + 1);

           
            int slide = f(s, i + 1, j + 1);

            ans = max(grow, slide);
        }

        return dp[i][j] = ans;
    }

    int maxPalindromes(string s, int K) {

        int n = s.size();

        k = K;

      
        isPalindrome.assign(n, vector<bool>(n, false));

      
        for (int l = 1; l <= n; l++) {

            for (int i = 0; i + l <= n; i++) {

                int j = i + l - 1;

                // Length 1
                if (i == j) {
                    isPalindrome[i][j] = true;
                }

                // Length 2
                else if (j == i + 1) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }

                // Length >= 3
                else {
                    if (s[i] == s[j] &&
                        isPalindrome[i + 1][j - 1]) {

                        isPalindrome[i][j] = true;
                    }
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        return f(s, 0, k - 1);
    }
};