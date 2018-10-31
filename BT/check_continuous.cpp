#include <iostream>
#include <queue>
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


void inorder(node* r){
    if(!r)
        return;
    inorder(r->left);
    cout<<r->val<<' ';
    inorder(r->right);
}

int check_dif(node* root){
    int f=1,s=1;
    if(root->left){
        if(abs(root->left->val - root->val)==1)
            int f = check_dif(root->left);
        else {
            return 0;
        }
    }

    if(root->right){
        if(abs(root->right->val - root->val)==1)
            int s = check_dif(root->right);
        else
            return 0;

    }

    return f&&s;

}

int main(){
    int a[]={3,4,4,3,5,5,5};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0;
    queue<node*>q;
    node *root=nn(a[0]);
    q.push(root);
    
    //form the tree given in array representation above
    while(!q.empty()) {
        node *t = q.front();
        q.pop();
        if (2*i +1 < n) {
            t->left = nn(a[2 * i + 1]);
            q.push(t->left);
        }
        if (2 * i + 2 < n) {
            t->right = nn(a[2 * i + 2]);
            q.push(t->right);
        }
        i++;
    }

    inorder(root);
    cout<<endl;
    cout<<check_dif(root);


}
