//https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool inorder(TreeNode* r,TreeNode* s){
        if(r==NULL && s==NULL) return true;
        if(r==NULL || s==NULL) return false;
        if(r->val==s->val) return inorder(r->left,s->left)&inorder(r->right,s->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL ) return false;
        if(inorder(root,subRoot)) return true;
        return isSubtree(root->left,subRoot)|isSubtree(root->right,subRoot);
    }
};