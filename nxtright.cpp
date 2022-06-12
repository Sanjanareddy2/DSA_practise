//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node* sol=root;
        queue<Node*> q;
        q.push(root);
        Node*side=NULL;
        while(!(q.empty())){
            int n = q.size();
            side=NULL;
            while(n--){
                Node*tmp = q.front();
                q.pop();
                if(tmp->right) q.push(tmp->right);
                if(tmp->left) q.push(tmp->left);
                tmp->next = side;
                side = tmp;
            }
        }
        return root;
        
    }