    //https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
    int i=0,j=0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[i++]);
        if(root->val != post[j])
            root->left = constructFromPrePost(pre,post);
        if(root->val != post[j])
            root->right = constructFromPrePost(pre,post);
        j++;
        return root;
    }