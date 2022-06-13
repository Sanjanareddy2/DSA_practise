/*If we traverse the tree in bottom-up manner, then we can pass information about subtrees to the parent. 
The passed information can be used by the parent to do BST test (for parent node) only in constant time (or O(1) time).
 A left subtree need to tell the parent whether it is BST or not and also needs to pass maximum value in it.
  So that we can compare the maximum value with the parent’s data to check the BST property.
   Similarly, the right subtree need to pass the minimum value up the tree. 
   The subtrees need to pass the following information up the tree for the finding the largest BST. 
1) Whether the subtree itself is BST or not (In the following code, is_bst_ref is used for this purpose) 
2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then minimum value in it. 
3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used for this purpose)
max_ref is used for passing the maximum value up the tree and min_ptr is used for passing minimum value up the tree. */

int largestBSTUtil(node* node, int *min_ref, int *max_ref,
                    int *max_size_ref, bool *is_bst_ref)
{
 
    /* Base Case */
    if (node == NULL)
    {
        *is_bst_ref = 1; // An empty tree is BST
        return 0; // Size of the BST is 0
    }
     
    int min = INT_MAX;
     
    /* A flag variable for left subtree property
        i.e., max(root->left) < root->data */
    bool left_flag = false;
     
    /* A flag variable for right subtree property
        i.e., min(root->right) > root->data */
    bool right_flag = false;
     
    int ls, rs; // To store sizes of left and right subtrees
     
    /* Following tasks are done by
    recursive call for left subtree
        a) Get the maximum value in left
        subtree (Stored in *max_ref)
        b) Check whether Left Subtree is
        BST or not (Stored in *is_bst_ref)
        c) Get the size of maximum size BST
        in left subtree (updates *max_size) */
    *max_ref = INT_MIN;
    ls = largestBSTUtil(node->left, min_ref, max_ref,
                        max_size_ref, is_bst_ref);
    if (*is_bst_ref == 1 && node->data > *max_ref)
        left_flag = true;
     
    /* Before updating *min_ref, store the min
    value in left subtree. So that we have the
    correct minimum value for this subtree */
    min = *min_ref;
     
    /* The following recursive call
    does similar (similar to left subtree)
    task for right subtree */
    *min_ref = INT_MAX;
    rs = largestBSTUtil(node->right, min_ref,
                        max_ref, max_size_ref, is_bst_ref);
    if (*is_bst_ref == 1 && node->data < *min_ref)
        right_flag = true;
     
    // Update min and max values for
    // the parent recursive calls
    if (min < *min_ref)
        *min_ref = min;
    if (node->data < *min_ref) // For leaf nodes
        *min_ref = node->data;
    if (node->data > *max_ref)
        *max_ref = node->data;
     
    /* If both left and right subtrees are BST.
    And left and right subtree properties hold
    for this node, then this tree is BST.
    So return the size of this tree */
    if(left_flag && right_flag)
    {
        if (ls + rs + 1 > *max_size_ref)
            *max_size_ref = ls + rs + 1;
        return ls + rs + 1;
    }
    else
    {
        // Since this subtree is not BST,
        // set is_bst flag for parent calls
        *is_bst_ref = 0;
        return 0;
    }
}