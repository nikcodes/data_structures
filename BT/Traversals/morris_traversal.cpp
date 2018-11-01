#include <iostream>
#include <stack>
using namespace std;

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


void moris_traversal(node* root){
    node *cur, *t;
    while(root) {
        if (!root->left) {
            cout << root->val << ' ';
            root = root->right;
        }

        else{
            cur=root->left;
            while(cur->right && cur->right!=root)
                cur=cur->right;

            if(!cur->right){
                cur->right=root;
                root=root->left;
            }
            else{
                cout<<root->val<<' ';
                cur->right=NULL;
                root=root->right;
            }
        }
    }
}


void inorder(node* r){
    if(!r)
        return;
    inorder(r->left);
    cout<<r->val<<' ';
    inorder(r->right);
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
    inorder(root);
    cout<<endl;
    moris_traversal(root);
}
