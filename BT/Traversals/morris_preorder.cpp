#include <iostream>
using namespace std;

struct node{
    int val,count,parts;
    node *left,*right,*next;
};

node* nn(int val) {
    node *t = new node;
    t->val = val;
    t->left = t->right = t->next = NULL;
    t->count = 0;
    t->parts = 0;
    return t;
}


void insert(node* root,int val){
    while(1){
        if(root->val>val){
            if(root->left)
                root=root->left;
            else
                break;
        }

        else if(root->val<val){
            if(root->right)
                root=root->right;
            else
                break;
        }
        else {
            root->count++;
            return;
        }

    }

    if(root->val<val)
        root->right=nn(val);
    else
        root->left=nn(val);
}


void moris_traversal_pre(node *root){
    node *cur,*t;
    while(root){
        if(!root->left){
            cout<<root->val<<' ';
            root=root->right;
        }

        else{
            cur=root->left;
            while(cur->right && cur->right!=root)
                cur=cur->right;

            if(!cur->right){
                cur->right=root;
                cout<<root->val<<' ';
                root=root->left;
            }
            else{
                cur->right=NULL;
                root=root->right;
            }
        }
    }
}

void pre(node* root){
    if(root){
        cout<<root->val<<' ';
        pre(root->left);
        pre(root->right);
    }
}





int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    node *root=nn(a[0]);
    for(int i=1;i<n;i++)
        insert(root,a[i]);
    pre(root);
    cout<<endl;
    moris_traversal_pre(root);
    post(root);

}
