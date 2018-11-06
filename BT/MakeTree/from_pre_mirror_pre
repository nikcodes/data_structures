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

node* from_mirror(int pre[],int prem[],int l,int r,int x,int y){
    if(r<l || y<x)
        return NULL;
    node*root=nn(pre[l]);
    if(l==r)
        return root;
    if((r-l)!=(y-x))
        cout<<l<<r<<x<<y<<endl;
    int sec;
    for(int i=x+1;i<=y;i++) {
        if (prem[i] == pre[l + 1]){
            sec = i;
            break;
        }
    }
    int leftsize=y-sec+1;
    root->left=from_mirror(pre,prem,l+1,l+leftsize,sec,y);
    root->right=from_mirror(pre,prem,l+leftsize+1,r,x+1,sec-1);
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
    node*root=from_mirror(a,b,0,n-1,0,n-1);
    inorder(root);
}
