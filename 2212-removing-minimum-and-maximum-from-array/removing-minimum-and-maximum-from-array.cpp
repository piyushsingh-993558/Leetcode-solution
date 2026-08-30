class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n=nums.size();
       int maximum=INT_MIN;
       int minimum=INT_MAX;
       int max_index_left=0;
       int min_index_left=0;
       for(int i=0;i<n;i++){
        maximum=max(maximum,nums[i]);
        minimum=min(minimum,nums[i]);
       }  
       for(int i=0;i<n;i++){
        if(nums[i]==maximum){
            max_index_left=i;
        }
        if(nums[i]==minimum){
            min_index_left=i;
        }
       }
       int min_index_right=n-1;
       int max_index_right=n-1;
        for(int i=n-1;i>=0;i--){
        if(nums[i]==maximum){
            max_index_right=i;
        }
        if(nums[i]==minimum){
            min_index_right=i;
        }
       }
     int global_left=0;
     int global_right=n-1;
    int d1=(min_index_left-0);
    int d2=(max_index_left-0);
    if(d1<d2){
        global_left=max_index_left;
    } else{
        global_left=min_index_left;
    }
    int d3= (n-1-min_index_right);
    int d4=(n-1-max_index_right);  
    if(d3<d4){
       global_right=max_index_right;    
    }else{
        global_right=min_index_left;
    }
     int D1=(global_left-0);
     int D2=(n-1-global_right);
     int total_ans1=0;
    if(D1<=D2){
     total_ans1=D1+1;           
    }else{
        total_ans1=D2+1;
    } 
     int total_ans2=0;
     if(d1<=d3){
    total_ans2+=d1+1;
     }else{
        total_ans2+=d3+1;
     }
     if(d2<=d4){
    total_ans2+=d2+1;
     }else{
        total_ans2+=d4+1;
     }
    return min(total_ans1,total_ans2);
     
    }
};