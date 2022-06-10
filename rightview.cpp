int ht(TreeNode* root){
        if(root==NULL) return 0;
        int x1 = ht(root->right);
        int x2 = ht(root->left);
        return max(x1,x2)+1;
    }
    void help(TreeNode* root, vector<int>&mp,int h){
        if(root==NULL) return;
        if(mp[h]==-102){
            mp[h]= root->val;
        }
        help(root->right,mp,h+1);
        help(root->left,mp,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> mp(ht(root),-102);
        help(root,mp,0);
        return mp;
    }