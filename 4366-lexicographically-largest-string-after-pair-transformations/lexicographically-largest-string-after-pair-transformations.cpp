class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
     int n=nums.size();
     vector<string>finalans; 
    for(int i=0;i<n;i++){
    string ans="";
    int x=nums[i];
    char ch='a';
    while(x!=1){
    if(x%2!=0){
        ans+=ch;
     }   
     x/=2;
     ch++;       
    }
    if(ch>'z'){
     ans+='z';
     ans+='z'; 
    } else{
        ans+=ch;
    }

    
    reverse(ans.begin(),ans.end());  
    finalans.push_back(ans);  
    }     
   return  finalans;           
    } 
};