class Solution {
public:
    int totalFruit(vector<int>& fruits) {
   unordered_map<int,int>mp;
   int i=0;
   int j=0;
   int n=fruits.size();
   int number_of_types=0;
   int maximum=0;
   while(j<n){
     
     if(mp.find(fruits[j])==mp.end()){
        mp[fruits[j]]++;
        number_of_types++;
        
     }else{
        mp[fruits[j]]++;
     } if(number_of_types>2){
        maximum=max(maximum,j-i);
          while(number_of_types>2){
        int x=fruits[i];
        mp[x]--;
        if(mp[x]==0){
         number_of_types--;
         mp.erase(x);
        } 
        i++;
     }
     } 
     j++;

   } 
   maximum=max(maximum,n-i);
    return maximum;       
    }
};