class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
       int n=nums.size();
   long long  total=0;
    for(auto &ele:nums){
       total+=ele;
    }   
    int length=n/2-1;
    for(int i=0;i<length;i++){
        nums.push_back(nums[i]);
    }    
  int m=nums.size();
  vector<long long>prefix(m);
  prefix[0]=nums[0];
  for(int i=1;i<m;i++){  
    prefix[i]=prefix[i-1]+nums[i];
  }   

   int i=0;
   int j=length;
   int ans=0;
   while(j<m){
    long long  sum=0;
    if(i==0){ 
        sum=prefix[j];
    }else{
        sum=prefix[j]-prefix[i-1];
    } 
    j++;
    i++;
    if(sum>total-sum){
        ans++; 
    } 
   } 
   return ans;   
    }
};