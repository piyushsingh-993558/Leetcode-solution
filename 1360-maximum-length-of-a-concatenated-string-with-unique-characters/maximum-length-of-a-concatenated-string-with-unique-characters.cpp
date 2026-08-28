class Solution {
public:

    int maximum = 0;

    void f(vector<string>& arr, string& ans, int i) {

        if(i == arr.size()) {
            maximum = max(maximum, (int)ans.size());
            return;
        }

        // Take arr[i] only if it keeps all characters unique
        bool possible = true;

        unordered_map<char,int> mp;

        for(char c : arr[i]) {
            if(mp[c] > 0) {
                possible = false;
                break;
            }
            mp[c]++;

            if(ans.find(c) != string::npos) {
                possible = false;
                break;
            }
        }

        if(possible) {
            ans += arr[i];

            f(arr, ans, i + 1);

            ans.erase(ans.size() - arr[i].size());
        }

        // Don't take
        f(arr, ans, i + 1);
    }

    int maxLength(vector<string>& arr) {

        string ans = "";

        f(arr, ans, 0);

        return maximum;
    }
};