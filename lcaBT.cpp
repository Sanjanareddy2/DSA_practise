// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
        if(root==NULL) return NULL;
    if( root->val == p->val || root->val == q->val )
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)
        return root;
    else
        return parent1 ? parent1:parent2;
}
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    return dfsTraverse(root, p, q);
}