//https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

Node* help (int pre[],int max,int min , int& pi,int size){
    if(pi>=size){
        return NULL;
    }
    Node*root = NULL;
    if(pre[pi]>min && pre[pi]<max){
        root = newNode(pre[pi++]);
        if(pi<size){
            root->left = help(pre,root->data,min,pi,size);
        }
        if(pi<size){
            root->right = help(pre,max,root->data,pi,size);
        }
    }
    return root;
}
Node* post_order(int pre[], int size)
{
    //code here
    Node*root=NULL;
    int pi=0;
    root = help(pre,INT_MAX,INT_MIN,pi,size);
    return root;
}