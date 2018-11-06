//Construct a special tree from given preorder traversal

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

void pre(node*root) {
    if (root) {
        cout << root->val << ' ';
        pre(root->left);
        pre(root->right);

    }
}

void inorder(node*root){
    if(root){
        inorder(root->left);
        cout<<root->val<<' ';
        inorder(root->right);
    }
}

node* form(int pre[],char type[],int n){
    stack<node*>s;
    node *root=nn(pre[0]), *top, *t;
    s.push(root);
    for(int i=1;i<n;i++){
        t=nn(pre[i]);
        if(!s.top()->left){
            s.top()->left=t;
            if(type[i]=='N')
                s.push(t);
        }
        else{
            s.top()->right=t;
            s.pop();
            if(type[i]=='N')
                s.push(t);
        }
    }
    return root;

}

int main(){
    cin>>n;
    int a[n];
    char b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<endl;
    node*root=form(a,b,n);
    inorder(root);


}
