
class Solution {
public:

    string result = "";

    bool solve(string& curr,
               vector<int>& count,
               string& target,
               int i,
               bool greater) {

        // We have constructed the complete string
        if (i == target.size()) {

            if (greater) {
                result = curr;
                return true;
            }

            return false;
        }

        // Try characters in lexicographical order
        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0)
                continue;

            // If we are still equal to target,
            // we cannot choose a smaller character.
            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            // Are we greater after choosing ch?
            bool isGreater = greater || (ch > target[i]);

            // If this choice gives us a valid answer,
            // return immediately.
            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            // Backtrack
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> count(26, 0);

        // Count characters of s
        for (char ch : s) {
            count[ch - 'a']++;
        }

        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};

