class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      int n=nums.size();
      vector<int>make;
      for(int i=0;i<n;i++){
        if(nums[i]<0){
            make.push_back(abs(nums[i]));
        }else{
            make.push_back(nums[i]);
        } 
      }
      int i=0;
      int j=n-1;
     sort(make.begin(),make.end());
     long long answer=0;
     while(i<j){
        answer+=make[j]*make[j];
     answer-=make[i]*make[i];
     
     i++;
     j--;
      }
      if(n%2!=0){
        answer+=make[n/2]*make[n/2];
      }  
      return answer;   
    }
};