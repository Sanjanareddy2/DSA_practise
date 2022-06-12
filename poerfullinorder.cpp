//https://leetcode.com/problems/recover-binary-search-tree/
TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void help(TreeNode* root){
        if(root==NULL) return;
        help(root->left);
        
        if(first==NULL && root->val < prev->val ) first = prev;
        if(first!=NULL && root->val < prev->val) second = root;
        prev = root;
        help(root->right);
    }
    void recoverTree(TreeNode* root) {
        help(root);
        int tmp = first->val;
        first->val=second->val;
        second->val=tmp;
    }