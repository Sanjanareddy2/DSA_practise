//https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    void doit(TreeNode* root){
        if(root==NULL) return ;
        TreeNode* lft = root->left;
        root->left = root->right;
        root->right = lft;
        doit(root->left);
        doit(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        doit(root);
        return root;
    }
};