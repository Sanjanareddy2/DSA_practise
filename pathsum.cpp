//https://leetcode.com/problems/path-sum/

bool helper(TreeNode* root, int targetSum, int sum){
        if(root->left==NULL && root->right==NULL){
            sum += root->val;
            if(sum==targetSum) return true;
            return false;
        }
        bool x1 = false,x2=false;
        if(root->left!=NULL) x1 = helper(root->left , targetSum, sum+ root->val);
        if(root->right!=NULL) x2 = helper(root->right , targetSum, sum+ root->val);
        return x1|x2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return helper(root,targetSum,0);
    }