
class Solution {
public:

    string finalans = "";
    string result = "";

   
    string makePalindrome(string half, char middle, int n) {

        string rev = half;
        reverse(rev.begin(), rev.end());

        if (n % 2 == 1) {
            return half + middle + rev;
        }

        return half + rev;
    }


    bool solve(string& curr, vector<int>& count,string& target,int i,  bool greater,char middle,int n) {

          if (i == n / 2) {

           
            string palindrome = makePalindrome(curr, middle, n);

          
            if (palindrome > target) {
                result = curr;
                finalans = palindrome;
                return true;
            }

            return false;
        }


        
        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0)
                continue;


          
            if (!greater && ch < target[i])
                continue;


            curr.push_back(ch);
            count[ch - 'a']--;


           
            bool isGreater = greater || (ch > target[i]);


            if (solve(curr, count,  target,i + 1,isGreater, middle,n)) {
                return true;
            }


         
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }


    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> count(26, 0);

      
        for (char ch : s) {
            count[ch - 'a']++;
        }



        int number_of_odd_freq = 0;
        char middle = ' ';

        for (int i = 0; i < 26; i++) {

            int value = count[i];

            if (value % 2 == 1) {
                middle = char('a' + i);
                number_of_odd_freq++;
            }

          
            count[i] = value / 2;
        }


       
        if (number_of_odd_freq > 1)
            return "";


        string curr = "";

        solve(curr,
             count,
             target,
             0,
             false,
             middle,
             n);


        return finalans;
    }
};

