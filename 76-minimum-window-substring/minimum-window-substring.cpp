class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
     unordered_map<int,int>mp;
     int n=t.size();
     for(int i=0;i<n;i++){
        mp[t[i]]++;        
     }  
    int found=0;
    int i=0;
    int j=0;
    int n2=s.size();
    unordered_map<int,int>mp2;
    int minimum=INT_MAX;
    int left=0;
    int right=0; 
    while(j<n2){
      if(mp.find(s[j])!=mp.end()){
        mp2[s[j]]++;
       int x=mp[s[j]];
       if(mp2[s[j]]==x){
        found++;
       }      
      }   
      while(found==mp.size()){
        if((j-i+1)<minimum){
          minimum=min(minimum,j-i+1);
      left=i;
      right=j;
        } 
        if(mp.find(s[i])!=mp.end()){
            mp2[s[i]]--;
        if(mp2[s[i]]<mp[s[i]]){
                found--;
         }      
        } 
         i++;
      }  
     j++; 
    } 
    if(minimum==INT_MAX) return "";
     string ans="";
     for(int i=left;i<=right;i++){
        ans+=s[i];
     } 
     return ans;            
    }
};