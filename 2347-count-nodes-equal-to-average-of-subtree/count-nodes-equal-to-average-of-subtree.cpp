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
    int ans=0;
    // unordered_map<int,int>mp;
    int f2(TreeNode* root){ 
        if(root==NULL) return 0;  
        int ans1=f2(root->left); 
        int ans2=f2(root->right);
        // mp[root->val]=1+ans1+ans2;
        return 1+ans1+ans2;
    }  
    int f1(TreeNode* root){ 
        if(root==NULL) return 0;
        int ans1=f1(root->left);
        int ans2=f1(root->right);
        int total_ans=root->val+ans1+ans2;
       
        int take=f2(root);
        if((total_ans)/take==root->val) ans++; 

         
        cout<<total_ans<<endl;  
        return total_ans;
    } 
    int averageOfSubtree(TreeNode* root) {
     
      int take=f1(root);
    
      return ans;
    }
};