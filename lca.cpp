// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val>= p->val && root->val <= q->val){
            return root;
        }
        if(root->val < p->val && root->val < q->val){
            return lca(root->right,p,q);
        }
        if(root->val > p->val && root->val > q->val){
            return lca(root->left,p,q);
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(p->val<q->val) return lca(root,p,q);
        if(p->val>q->val) return lca(root,q,p);
        return NULL;
    }