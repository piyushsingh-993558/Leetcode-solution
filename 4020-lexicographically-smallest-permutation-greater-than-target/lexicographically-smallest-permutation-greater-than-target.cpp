class Solution {
public:

    string ans = "";

    bool f(string &target, vector<int>& freq, int i, bool greater) {

        int n = target.size();

        // All positions are filled
        if(i == n) {
            return greater;
        }

        int x = target[i] - 'a';

        // If we are already greater,
        // simply take the smallest available character.
        if(greater) {

            for(int c = 0; c < 26; c++) {

                if(freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    if(f(target, freq, i + 1, true))
                        return true;

                    freq[c]++;
                    ans.pop_back();
                }
            }

            return false;
        }

        // We are still equal to target.
        // First try target[i].
        if(freq[x] > 0) {

            ans += target[i];
            freq[x]--;

            if(f(target, freq, i + 1, false))
                return true;

            freq[x]++;
            ans.pop_back();
        }

        // Matching target[i] didn't work.
        // Try the smallest character greater than target[i].
        for(int c = x + 1; c < 26; c++) {

            if(freq[c] > 0) {

                ans += char('a' + c);
                freq[c]--;

                if(f(target, freq, i + 1, true))
                    return true;

                freq[c]++;
                ans.pop_back();
            }
        }

        return false;
    }


    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        if(f(target, freq, 0, false))
            return ans;

        return "";
    }
};