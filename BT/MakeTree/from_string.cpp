#include <iostream>
#include <stack>
using namespace std;
int n,i;

struct node{
    char val;
    node *left,*right;

};

node* nn(int val){
    node* t = new node;
    t->val=val;
    t->left=t->right=NULL;
    return t;
}


node* form(string s,int n){
    node*root=nn(s[0]), *cur, *t;
    stack<node*> st;
    st.push(root);
    for(int i=1;i<n;i++){
        if(s[i]=='(' || s[i]==')')
            continue;
        cur=nn(s[i]);
        t=st.top();

        if(t->left){
            t->right=cur;
            st.pop();
        }

        else
            t->left=cur;

        if(!(s[i-1]=='(' && s[i+1]==')'))
            st.push(cur);
    }
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
    string s;
    cin>>s;
    int n=s.length();
    node*root=form(s,n);
    inorder(root);

}
