//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
int ht(TreeNode* root){
        if(root==NULL) return 0;
        int x1 = ht(root->left);
        int x2 = ht(root->right);
        return max(x1,x2)+1;
    }
    void help(TreeNode* root, int i, vector<vector<int>> &sol){
        if(root==NULL) return;
        sol[i].push_back(root->val);
        help(root->left, i+1, sol);
        help(root->right, i+1, sol);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol(ht(root));
        help(root,0,sol);
        return sol;
    }