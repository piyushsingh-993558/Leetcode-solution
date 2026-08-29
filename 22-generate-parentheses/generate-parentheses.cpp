class Solution {
public:
    vector<string> ans;

    void f(int n, string& curr, int open, int close) {

      
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        
        if (open < n) {
            curr.push_back('(');
            f(n, curr, open + 1, close);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            f(n, curr, open, close + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        f(n, curr, 0, 0);
        return ans;
    }
};