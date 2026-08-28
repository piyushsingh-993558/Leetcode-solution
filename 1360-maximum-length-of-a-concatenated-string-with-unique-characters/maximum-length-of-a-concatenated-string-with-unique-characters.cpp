class Solution {
public:

    int maximum = 0;

    void f(vector<string>& arr, int i, int mask, int length) {

        
        if(i == arr.size()) {
            maximum = max(maximum, length);
            return;
        }

       
        f(arr, i + 1, mask, length);

      
        int newMask = mask;
        bool possible = true;

        for(char c : arr[i]) {

            int bit = 1 << (c - 'a');

           
            if(newMask & bit) {
                possible = false;
                break;
            }

            newMask |= bit;
        }

      
        if(possible) {
            f(arr, i + 1, newMask, length + arr[i].size());
        }
    }

    int maxLength(vector<string>& arr) {

        f(arr, 0, 0, 0);

        return maximum;
    }
};