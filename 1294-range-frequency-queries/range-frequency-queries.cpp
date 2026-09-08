class RangeFreqQuery {
public:

    vector<unordered_map<int, int>> st;
    int n;

    // Merge two child maps into parent
    void fill(unordered_map<int, int>& mp1,
              unordered_map<int, int>& mp2,
              int i) {

        // Copy left child's frequencies
        st[i] = mp1;

        // Add right child's frequencies
        for (auto &ele : mp2) {
            st[i][ele.first] += ele.second;
        }
    }

    // Build segment tree
    void buildTree(vector<int>& arr, int i, int lo, int hi) {

        // Leaf node
        if (lo == hi) {
            st[i][arr[lo]]++;
            return;
        }

        int mid = (lo + hi) / 2;

        // Build left child
        buildTree(arr, 2 * i + 1, lo, mid);

        // Build right child
        buildTree(arr, 2 * i + 2, mid + 1, hi);

        // Merge children
        fill(
            st[2 * i + 1],
            st[2 * i + 2],
            i
        );
    }

    // Query frequency of value in [left, right]
    int get(int i, int lo, int hi,
            int left, int right, int value) {

        // No overlap
        if (right < lo || left > hi) {
            return 0;
        }

        // Complete overlap
        if (left <= lo && hi <= right) {

            auto it = st[i].find(value);

            if (it != st[i].end()) {
                return it->second;
            }

            return 0;
        }

        // Partial overlap
        int mid = (lo + hi) / 2;

        int leftFreq = get(
            2 * i + 1,
            lo,
            mid,
            left,
            right,
            value
        );

        int rightFreq = get(
            2 * i + 2,
            mid + 1,
            hi,
            left,
            right,
            value
        );

        return leftFreq + rightFreq;
    }

    RangeFreqQuery(vector<int>& arr) {

        n = arr.size();

        st.resize(4 * n);

        buildTree(arr, 0, 0, n - 1);
    }

    int query(int left, int right, int value) {

        return get(
            0,
            0,
            n - 1,
            left,
            right,
            value
        );
    }
};