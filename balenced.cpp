//https://leetcode.com/problems/balanced-binary-tree/

int ht(TreeNode* root,bool &sol){
        if(root==NULL) {
            return 0;
        }
        int x1 = ht(root->left,sol);
        int x2 = ht(root->right,sol);
        if(abs(x1-x2)>1) {
            sol=false;
            return -1;
        }
        
        return 1+max(x1,x2);
        
    }
    bool isBalanced(TreeNode* root) {
        bool sol = true;
        int x = ht(root,sol);
        return sol;
    }