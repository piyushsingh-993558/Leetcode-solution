class Solution {
public:
    int countCommas(int n) {
       
      
        int total_commas=0;
    for(int i=1;i<=n;i++){
      int number_of_digit_computed=0;
       
      int x=i; 
      while(x>0){
        x/=10; 
       number_of_digit_computed++;
 
       } 
      if(number_of_digit_computed%3==0){
         total_commas+=(number_of_digit_computed/3)-1;
      }else{
      total_commas+=(number_of_digit_computed/3);  
      } 
   
    }
    return total_commas;   
      
    }
};