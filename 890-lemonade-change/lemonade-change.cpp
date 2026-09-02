class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    // int twenty=0;
    int five=0;
    int ten=0;
    int n=bills.size();
    for(int i=0;i<n;i++) {
      if(bills[i]==5){
        five++;
      } 
      else if(bills[i]==10){
        ten++;
         int required_note=(bills[i]-5)/5;
         if(five>=required_note){
            five-=required_note;
         }else{
            return false;
         }
      }else{
    //  twenty++;
    // int ten_note=1;
    // int five_note=3;
    if(ten>=1&&five<1){
         return false;  
    }
    if(ten<1&&five<3) return false;
    if(ten<1&&five>=3){
        five-=3;
    }
    if(ten>=1&&five>=1){
        ten-=1;
        five-=1;
    }  

      }   
    
    }  
     return true;         
    }
};