
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    }; 

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;
        long long s = seg[node].sum;

        seg[node].sq = (
            seg[node].sq
            + 2LL * v % MOD * s
            + v * v % MOD * len
        ) % MOD;

        seg[node].sum = (s + v * len) % MOD;
        seg[node].lazy = (seg[node].lazy + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return; 

        int mid = l + (r - l) / 2;
        long long v = seg[node].lazy;
          
        apply(node * 2, l, mid, v);
        apply(node * 2 + 1, mid + 1, r, v);
   
        seg[node].lazy = 0;
    }

    void pull(int node) {
        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            update(1, 0, n - 1, last[x] + 1, i);

            last[x] = i;

            ans = (ans + seg[1].sq) % MOD;
        } 

        return ans;
    }
};
