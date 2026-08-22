class Solution {
public:
    bool checkDivisibility(int n) {
        int copy=n;
    
    int sum_part=0;
    int product_part=1;
    while(copy>0){
   int rem=copy%10;
   sum_part+=rem;
   product_part*=rem;
   copy/=10;     
    } 
    return (n%(sum_part+product_part)==0)?1:0;  
    // return (n%(sum_part+product_part))?1:0;     
    }
};