//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/?currentPage=1&orderBy=most_votes&query=

TreeNode* helper(vector<int>& nums, int i, int j){
        if(i>j) return NULL;
        int mid = (j+i)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums,i,mid-1);
        root->right = helper(nums,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }