class Solution {
public:
    long long countCommas(long long n) {

        long long commas = 1;
        long long initial = 1000;
        long long total_ans = 0;
         int number_of_zeros=3;
        while (initial <= n) {

            long long end = 10 * initial - 1;
            bool check = true;
            number_of_zeros++;
            
            if (end > n) {

                long long s = initial;
                long long e = end;

                while (s <= e) {

                    long long mid = s + (e - s) / 2;

                    if (mid == n) {
                        end = mid;
                        check = false;
                        break;
                    }
                    else if (mid > n) {
                        e = mid - 1;
                    }
                    else {
                        s = mid + 1;
                    }
                }
            }

            total_ans += commas * (end - initial + 1);

            if (check == false)
                break;

            initial = end+1;
           if(number_of_zeros%3==0){
               commas++;
           }
            
        }

        return total_ans;
    }
};