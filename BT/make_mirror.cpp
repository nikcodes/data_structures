#include <iostream>
using namespace std;

struct node{
    int val;
    node *left,*right;
};

node* nn(int val){
    node* t = new node;
    t->val=val;
    t->left=t->right=NULL;
    return t;
}


void insert(node *root,int val){
    while(1){
        if(root->val > val){
            if(root->left)
                root=root->left;
            else
                break;
        }
        else if(root->val < val){
            if(root->right)
                root=root->right;
            else
                break;
        }
    }

    if(root->val < val)
        root->right=nn(val);
    else
        root->left=nn(val);
}

void inorder(node* r){
    if(!r)
        return;
    inorder(r->left);
    cout<<r->val<<' ';
    inorder(r->right);
}

void mirror(node *root){
    if(!root)
        return;
    if(!root->left && !root->right)
        return;
    node *t;
    t=root->right;
    root->right=root->left;
    root->left=t;
    mirror(root->left);
    mirror(root->right);

}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    node* root=nn(a[0]);
    for(int i=1;i<n;i++)
        insert(root,a[i]);
    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);
    
}
