//https://leetcode.com/problems/diameter-of-binary-tree/
int diameterOfBinary(TreeNode* root,int &d) {
        if(root==NULL) return 0;
        int x1 = diameterOfBinary(root->left,d);
        int x2 = diameterOfBinary(root->right,d);
        d = max(d,x1+x2);
        return max(x1,x2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d =0;
        diameterOfBinary(root,d);
        return d;
    }
