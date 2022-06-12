//https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

void help (Node* &root,int pre[],int i,int j){
    if(i>j){
        root=NULL;
        return;
    }
    (root) = newNode( pre[i]);
    //(*root)->data =;
    if(i==j) return;
    int k = i+1;
    while(pre[i]>pre[k]) k++;
    help(root->left,pre,i+1,k-1);
    help(root->right,pre,k,j);
}
Node* post_order(int pre[], int size)
{
    //code here
    Node*root=NULL;
    help(root,pre,0,size-1);
    return root;
}
