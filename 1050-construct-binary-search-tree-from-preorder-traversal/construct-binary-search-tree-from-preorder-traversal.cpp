/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* f(vector<int>&preorder,int& i,int bound){
    int n=preorder.size();
    if(i==n) return NULL;
    if(preorder[i]>bound) return NULL;
    TreeNode* node=new TreeNode(preorder[i]);
    i++; 
    node->left=f(preorder,i,node->val);
    node->right=f(preorder,i,bound);
    return node;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return f(preorder,i,INT_MAX);
    }

};