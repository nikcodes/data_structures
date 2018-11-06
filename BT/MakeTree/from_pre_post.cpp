//iterative preorder traversal

#include <iostream>
#include <map>
using namespace std;

int n;
struct node{
    int val,count;
    node *left,*right;

};

node* nn(int val){
    node* t = new node;
    t->val=val;
    t->left=t->right=NULL;
    t->count=0;
    return t;
}

void insert(node *root,int val) {
    while (1) {
        if (root->val > val) {
            if (root->left)
                root = root->left;
            else
                break;
        }

        else if (root->val < val) {
            if (root->right)
                root = root->right;
            else
                break;
        }

        else{
            root->count++;
            return;
        }
    }

    if (root->val < val)

        root->right=nn(val);

    else
        root->left=nn(val);

}

void pre(node*root) {
    if (root) {
        cout << root->val << ' ';
        pre(root->left);
        pre(root->right);

    }
}

node* form(int pre[],int post[],int l,int r,int x,int y){
    if(l>r)
        return NULL;
    if(l==r)
        return nn(pre[l]);
        
    int postindex;
    node*root=nn(pre[l]);

    for(int i=x;i<y;i++){
        if(post[i]==pre[l+1]){
            postindex=i;
            break;
        }
    }

    int leftsize=postindex-x+1;

    root=nn(pre[l]);
    root->left=form(pre,post,l+1,l+leftsize,x,x+leftsize-1);
    root->right=form(pre,post,l+leftsize+1,r,x+leftsize,y-1);

    return root;

}

void inorder(node*root){
    if(root){
        inorder(root->left);
        cout<<root->val<<' ';
        inorder(root->right);
    }
}

int main(){
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    node*root=form(a,b,0,n-1,0,n-1);
    inorder(root);


}
