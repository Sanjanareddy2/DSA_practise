//https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

void cnt(Node *root, int l, int h,int&sol){
        if(root==NULL) return ;
        if(root->data>=l && root->data<=h) sol++;
        cnt(root->left,l,h,sol);
        cnt(root->right,l,h,sol);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      int x =0;
      cnt(root,l,h,x);
      return x;
    }