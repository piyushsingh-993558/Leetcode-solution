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
    vector<int>inorder;
    void f(TreeNode* root){
        if(root==NULL) return;
        f(root->left);
        inorder.push_back(root->val);
        f(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
       
        unordered_set<int>st;
        f(root);  
         int n=inorder.size();
           for(int i=0;i<n;i++){
             cout<<inorder[i]<<endl;
          
             if(st.find(k-inorder[i])!=st.end()) return true;
             st.insert(inorder[i]); 
           }
            return false;
    }
};