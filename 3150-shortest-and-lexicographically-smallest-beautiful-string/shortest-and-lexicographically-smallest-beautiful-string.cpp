class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        vector<int> indices;

      
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                indices.push_back(i);
            }
        }

       
        if (indices.size() < k)
            return "";

        int minimum = INT_MAX;
        string finalans = "";

        for (int i = 0; i + k - 1 < indices.size(); i++) {

            int left = indices[i];
            int right = indices[i + k - 1];

            int len = right - left + 1;

            string candidate = s.substr(left, len);

            if (len < minimum) {

                minimum = len;
                finalans = candidate;

            }
            else if (len == minimum && candidate < finalans) {

                finalans = candidate;
            }
        }

        return finalans;
    }
};