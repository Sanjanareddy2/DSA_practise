//https://leetcode.com/problems/validate-binary-search-tree/
 bool isValidBST(TreeNode* root, long  mn, long mx) {
        if(!root) {
            return true;
        }
        if(root->val < mn or root->val > mx) {
            return false;
        }
        return isValidBST(root->left, mn, 0ll+ root->val-1) and 
            isValidBST(root->right, 1ll + root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }