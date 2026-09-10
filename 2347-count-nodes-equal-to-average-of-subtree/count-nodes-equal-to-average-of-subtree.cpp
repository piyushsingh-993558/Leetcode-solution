class Solution {
public:
    int ans = 0;

    pair<int, int> f1(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = f1(root->left);
        pair<int, int> right = f1(root->right);

        int total_sum = root->val + left.first + right.first;
        int total_count = 1 + left.second + right.second;

        if (total_sum / total_count == root->val)
            ans++;

        return {total_sum, total_count};
    }

    int averageOfSubtree(TreeNode* root) {
        f1(root);
        return ans;
    }
};