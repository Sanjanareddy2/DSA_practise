// https://leetcode.com/problems/maximum-depth-of-binary-tree/

int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int x1 = maxDepth(root->left);
        int x2 = maxDepth(root->right);
        return max(x1,x2)+1;
}