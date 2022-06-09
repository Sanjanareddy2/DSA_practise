//https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/

void inorder(TreeNode* root,vector<int>& s){
        if(root==NULL) return;
        inorder(root->left,s);
        s.push_back(root->val);
        inorder(root->right,s);
    }
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> s;
        inorder(root,s);
        int n = s.size();
        //cout << n;
        int min = INT_MAX;
        for(int i=1;i<n;i++){
            if(min > s[i]-s[i-1]) min = s[i]-s[i-1];
        }
        return min;
    }