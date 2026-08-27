  class Solution {
  public:
    int characterReplacement(string s, int k) { 
     int n= s.size();
     unordered_set<char>st;
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    } 
    vector<char>store;
    for(auto ele:st){ 
     store.push_back(ele);      
    }  
    int overall_maximum=0;
    for(int i=0;i<store.size();i++){
     int maximum=0;     
     int m=0;
     int j=0;
     char ch=store[i];
     int change=0;
     vector<int>mark(n,0);
     while(m<n){
     if(s[m]!=ch){ 
       change++;
       mark[m]=1;
    }       
    while(change>k){ 
      if(mark[j]==1){
        mark[j]==0;
        change--;
      }  
      j++;    
    } 
    maximum=max(maximum,m-j+1); 
    m++;  
     } 
      overall_maximum=max(overall_maximum,maximum);    
     }
     return overall_maximum;             
    }
};