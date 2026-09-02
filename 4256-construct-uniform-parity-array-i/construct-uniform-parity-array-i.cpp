class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        
        bool oddPossible = true;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                bool foundOdd = false;

                for (int j = 0; j < n; j++) {
                    if (i != j && nums1[j] % 2 == 1) {
                foundOdd = true;
                        break;
                    }
                }

                if (!foundOdd) {
                    oddPossible = false;
                    break;
                }
            }
        }

        if (oddPossible)
            return true;

        
        bool evenPossible = true;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                bool foundOdd = false;

                for (int j = 0; j < n; j++) {
                    if (i != j && nums1[j] % 2 == 1) {
                        foundOdd = true;
                        break;
                    }
                }

                if (!foundOdd) {
                    evenPossible = false;
                    break;
                }
            }
        }

        return evenPossible;
    }
};  