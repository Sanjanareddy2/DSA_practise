//https://leetcode.com/problems/binary-tree-paths/

void helper(TreeNode* root, string t , vector<string>& sol){
        if(root->left==NULL && root->right==NULL){
            t = t+ to_string(root->val);
            sol.push_back(t);
            return ;
        }
        if(root->left!=NULL) helper(root->left,t+to_string(root->val)+"->",sol);
        if(root->right!=NULL) helper(root->right,t+to_string(root->val)+"->",sol);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        helper(root,"",s);
        return s;
    }