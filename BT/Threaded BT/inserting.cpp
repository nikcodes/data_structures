#include <iostream>
#include <stack>
using namespace std;

struct node{
    int val,trav;
    node *left,*right,*pre,*nex;

};

node* nn(int val){
    node* t = new node;
    t->val=val;
    t->left=t->right=t->nex=t->pre=NULL;
    t->trav=0;
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
    }

    if (root->val < val) {

        root->right=nn(val);
        node*t=root->right;
        t->pre=root;
        t->nex=root->nex;
        root->nex= NULL;

    }

    else {
        root->left=nn(val);
        node *t=root->left;
        t->nex=root;
        t->pre=root->pre;
        root->pre=0;


    }
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


}
