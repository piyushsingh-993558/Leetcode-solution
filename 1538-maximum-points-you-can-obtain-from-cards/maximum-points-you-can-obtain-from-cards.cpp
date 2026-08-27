class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n=cardPoints.size();
      int maximum=0;
      int left_sum=0;
      for(int i=0;i<k;i++){
      left_sum+=cardPoints[i];
      } 
      maximum=max(maximum,left_sum);
      int right_index=n-1;
      int right_sum=0;
      for(int i=k-1;i>=0;i--){
      left_sum=left_sum-cardPoints[i];
      right_sum=right_sum+cardPoints[right_index];
      right_index--;
      maximum=max(maximum,left_sum+right_sum);    
      }
      return maximum;   
    }
};