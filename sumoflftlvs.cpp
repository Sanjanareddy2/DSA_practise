//https://leetcode.com/problems/sum-of-left-leaves/submissions/

void helper(TreeNode* root,int &sol,bool lft){
        if(root->left==NULL && root->right==NULL){
            if(lft) sol+= root->val;
            return;
        }
        //if(lft) sol+= root->val;
        if(root->left!=NULL) helper(root->left,sol,true);
        if(root->right !=NULL) helper(root->right,sol,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sol=0;
        helper(root,sol,false);
        return sol;
    }