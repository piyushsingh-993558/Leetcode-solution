
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        unordered_set<int> st;

        for(int i = 0; i < arr2.size(); i++) {
            st.insert(arr2[i]);
        }

        int n = arr1.size();
        int results = 0;

        for(int i = 0; i < n; i++) {
            int extend = arr1[i] + d;
            int minimize = arr1[i] - d;

            bool possible = false;

            for(int j = minimize; j <= extend; j++) {
                if(st.find(j) != st.end()) {
                    possible = true;
                    break;
                }
            }

            if(!possible) results++;
        }

        return results;
    }
};
