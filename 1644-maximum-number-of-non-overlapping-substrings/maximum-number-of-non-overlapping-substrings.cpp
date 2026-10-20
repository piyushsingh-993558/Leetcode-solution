// Bilkul! Hum tumhare approach ke according hi code likhenge:
// 1. Har character ka first aur last index find karo.
// 2. Har character ki initial range [first, last] banao.
// 3. Range ke andar characters check karo. Agar kisi character ka last index current end se aage hai, toh end ko dynamically expand karo.
// 4. Agar kisi character ka first index current start se pehle hai, toh range invalid hai.
// 5. Saari valid ranges mein se maximum number of non-overlapping substrings find karo.

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Step 1: Find first and last index
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (first[c] == -1) {
                first[c] = i;
            }

            last[c] = i;
        }

        vector<pair<int, int>> ranges;

        // Step 2: Create and dynamically expand ranges
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) {
                continue;
            }

            int start = first[c];
            int end = last[c];
            bool valid = true;

            for (int i = start; i <= end; i++) {
                int ch = s[i] - 'a';

                // Character has an occurrence before start
                if (first[ch] < start) {
                    valid = false;
                    break;
                }

                // Dynamically expand the range
                if (last[ch] > end) {
                    end = last[ch];
                }
            }

            if (valid) {
                ranges.push_back({start, end});
            }
        }

        // Step 3: Sort ranges by ending index
        sort(ranges.begin(), ranges.end(),
             [](const auto& a, const auto& b) {
                 if (a.second != b.second) {
                     return a.second < b.second;
                 }
                 return a.first > b.first;
             });

        // Step 4: Select non-overlapping ranges
        vector<string> ans;
        int lastEnd = -1;

        for (auto [start, end] : ranges) {
            if (start > lastEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }

        return ans;
    }
};