class Solution {
public:
    bool isPalindromic(string s) {
   int n=s.size();
   string final="";
   for(int i=0;i<n;i++){
    char ch=s[i];
    int ascii=(char)ch;
    string make="";
    int x=ascii;
    int no_of_eights=0;
    while(x!=1){
    make+=x%2+'0';
     x/=2;
    no_of_eights++;
    }
    make+='1';
    no_of_eights++;
    while(no_of_eights!=8){
        make+='0';
        no_of_eights++;
    }
    reverse(make.begin(),make.end());
    final+=make;
   } 
   int i=0;
   int j=final.size()-1;
   while(i<j){
    if(final[i]!=final[j]) return false;
    j--;
    i++;
   }   
    return true;     
    }
};