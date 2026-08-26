class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        int i = 0;       // left
        int j = 0;       // right
        int cnt = 0;     // number of 1s

        int bestLen = INT_MAX;
        string ans = "";

        while (j < n) {

           
            if (s[j] == '1')
                cnt++;

          
            while (cnt == k) {

                int len = j - i + 1;

                string curr = s.substr(i, len);

                
                if (len < bestLen) {
                    bestLen = len;
                    ans = curr;
                }

              
                else if (len == bestLen && curr < ans) {
                    ans = curr;
                }

               
                if (s[i] == '1')
                    cnt--;

                i++;
            }

            
            j++;
        }

        return ans;
    }
};