//https://leetcode.com/problems/path-sum-ii/
void help(TreeNode* root, int targetSum, vector<int> &s, vector<vector<int>> &sol){
        if(root->left==NULL && root->right==NULL){
            if(root->val==targetSum) {
                s.push_back(root->val);
                sol.push_back(s);
                s.pop_back();
            }
            return;
        }
        
        
        if(root->left) {
            s.push_back(root->val);
            help(root->left,targetSum-root->val,s,sol);
            s.pop_back();
        }
        if(root->right){
            s.push_back(root->val);
            help(root->right,targetSum-root->val,s,sol);
            s.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>> sol;
        vector<int> s;
        help(root,targetSum,s,sol);
        return sol;
    }