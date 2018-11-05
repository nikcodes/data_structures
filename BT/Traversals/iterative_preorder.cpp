//iterative preorder traversal

#include <iostream>
#include <stack>
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

void pre(node*root){
    if(root){
        cout<<root->val<<' ';
        pre(root->left);
        pre(root->right);

    }
}

void pre_iterative(node*root){
    stack<node*>a;
    while(!a.empty() || root) {
        if(root){
            a.push(root);
            cout<<root->val<<' ';
            root=root->left;
        }
        else {
            node *t = a.top()->right;
            if (t)
                root = t;
            else {
                t=a.top();
                a.pop();
                while(!a.empty() && t==a.top()->right){
                    t=a.top();
                    a.pop();
                }
                if(a.empty())
                    break;
                root=a.top()->right;
            }
        }
    }
    cout<<endl;
}

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    node* root=nn(a[0]);
    for(int i=1;i<n;i++)
        insert(root,a[i]);
    pre_iterative(root);
    pre(root);


}
