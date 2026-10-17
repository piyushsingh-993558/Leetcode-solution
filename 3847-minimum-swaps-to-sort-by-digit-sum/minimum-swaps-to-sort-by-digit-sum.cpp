
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

       
        for (int x : nums) {
            int sum = 0;
            int temp = x;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            pq.push({sum, x});
        }

       
        vector<int> sorted;
        while (!pq.empty()) {
            sorted.push_back(pq.top().second);
            pq.pop();
        } 

       
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

       
        int swaps = 0;
     
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i])
                continue;
             
            int j = pos[sorted[i]];
           
            swap(nums[i], nums[j]);

            pos[nums[j]] = j;
            pos[nums[i]] = i;

            swaps++;
        }

        return swaps;
    }
};
