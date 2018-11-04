//reverse path from root to a particular node 

#include <iostream>
#include <deque>
#include <map>
#define pb push_back

using namespace std;
int i=0; // is the global variable to point to the root of the current subtree

struct node{
    node *left,*right;
    int val;
};

node* nn(int val){
    node*t=new node;
    t->val=val;
    t->left=t->right=NULL;
    return t;
}



deque<node*> f(node*root,int target){
    if(!root){
        deque<node*>a;
        return a;
    }
    if(root->val==target){
        deque<node*>t;
        t.pb(root);
        return t;
    }
    deque<node*>left = f(root->left,target);
    deque<node*>right = f(root->right,target);
    if(left.empty() && right.empty()) {
        deque<node*>a;
        return a;
    }
    if(!left.empty()){
        left.pb(root);
        return left;
    }
    else{
        right.pb(root);
        return right;
    }
}

void inorder(node*root){
    if(root){
        inorder(root->left);
        cout<<root->val<<' ';
        inorder(root->right);
    }
}

int main(){
    node* root=nn(34);
    root->left=nn(23);
    root->right=nn(45);
    root->left->right=nn(25);
    root->right->right=nn(40);
    root->right->left=nn(50);
    
    cout<<"inorder traversal before reversing the path";
    inorder(root);
    cout<<endl;

    deque<node*>a=f(root,45);
    int t;

    while(!a.empty()){
        node* fir=a.front();
        node* last=a.back();
        if(fir==last)
            break;
        t=fir->val;
        fir->val=last->val;
        last->val=t;
        a.pop_back();
        a.pop_front();
    }

    cout<<"inorder traversal after reversing the path";
    inorder(root);



}
