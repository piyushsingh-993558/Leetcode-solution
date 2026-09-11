class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
    int n=position.size();
    vector<int>s;
    s.push_back(speed[0]);
    for(int i=1;i<n;i++){
    if(position[i]-position[i-1]<=distance){
        s.pop_back();
    }
      s.push_back(speed[i]);
    }
    int min_speed=INT_MAX;
    int ans=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]<=min_speed){
            ans++;
            min_speed=s[i];
        }
    }
     return ans;    
    }
};