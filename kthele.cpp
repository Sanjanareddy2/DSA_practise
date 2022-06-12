//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
void inorder(TreeNode* root, int k,vector<int>&s){
        if(root==NULL) return;
        
        inorder(root->left,k,s);
        s.push_back(root->val);
        inorder(root->right,k,s);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> s;
        inorder(root,k,s);
        return s[k-1];
    }


/*Follow up
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Click here to learn how to insert a node into a BST and delete a node from a BST, the time complexity of these operations is O(H)O(H), where HH is a height of the binary tree. H = \log NH=logN for the balanced tree and H = NH=N for a skewed tree.

Hence without any optimisation insert/delete + search of kth element has O(2H + k)O(2H+k) complexity. How to optimise that?

That's a design question, basically we're asked to implement a structure which contains a BST inside and optimises the following operations :

Insert

Delete

Find kth smallest

Seems like a database description, isn't it? Let's use here the same logic as for LRU cache design, and combine an indexing structure (we could keep BST here) with a double linked list.

Such a structure would provide:

O(H)O(H) time for the insert and delete.

O(k)O(k) for the search of kth smallest.

bla

The overall time complexity for insert/delete + search of kth smallest is O(H + k)O(H+k) instead of O(2H + k)O(2H+k).

Complexity Analysis

Time complexity for insert/delete + search of kth smallest: O(H + k)O(H+k), where HH is a tree height. O(\log N + k)O(logN+k) in the average case, O(N + k)O(N+k) in the worst case.

Space complexity : O(N)O(N) to keep the linked list.*/