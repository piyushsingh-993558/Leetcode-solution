class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 1;
        long long initial = 1000;
        long long total_ans = 0;
        int number_of_zeros=3;
        while (initial <= n) {
            long long end = 10 * initial - 1;
             number_of_zeros++;
             if (end > n){
                end = n;
                }
         total_ans += commas * (end - initial + 1); 

            initial = end + 1;
            if(number_of_zeros%3==0){
                  commas++; 
            }
           
        
     
        }
           return total_ans;
    }
};