//https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int x =0;
        if(root->val <=high && root->val >=low) x = root->val;
        return x+ rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};