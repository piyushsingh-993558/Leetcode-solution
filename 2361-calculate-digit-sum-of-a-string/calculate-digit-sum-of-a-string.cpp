
class Solution {
public:
    string digitSum(string s, int k) {

        string t = s;

        while(t.size() > k) {

            string temp = "";
            int sum = 0;
            int count = 0;

            for(int i = 0; i < t.size(); i++) {

                sum += t[i] - '0';
                count++;

                if(count == k) {
                    temp += to_string(sum);
                    count = 0;
                    sum = 0;
                }
            }

            if(count > 0) {
                temp += to_string(sum);
            }

            t = temp;
        }

        return t;
    }
};
