//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->left==NULL&& root->right==NULL) return;
        flatten(root->left);
        if(root->left!=NULL){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left=NULL;
            while(root->right) root=root->right;
            root->right = temp;
        }
        flatten(root->right);
        
    }
};