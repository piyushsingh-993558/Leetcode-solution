class Solution {
public:
    vector<string> finalans;

    bool isValid(string& curr) {
        int ptr = 0;

        for (int i = 0; i < curr.size(); i++) {

            if (curr[i] == '(') {
                ptr++;
            }
            else {
                ptr--;

                if (ptr < 0)
                    return false;
            }
        }

        return ptr == 0;
    }

    void f(int n, string& curr) {

        // Base case
        if (curr.size() == 2 * n) {

            if (isValid(curr)) {
                finalans.push_back(curr);
            }

            return;
        }

      
        curr.push_back('(');
        f(n, curr);
        curr.pop_back();

       
        curr.push_back(')');
        f(n, curr);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";

        f(n, curr);

        return finalans;
    }
};