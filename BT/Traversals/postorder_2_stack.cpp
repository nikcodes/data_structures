//post order traversal with 2 stacks

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


void post_2_stack(node*root){
    stack<node*>a,b;
    a.push(root);
    while(!a.empty()){
        node*t=a.top();
        a.pop();
        b.push(t);
        if(t->left)
            a.push(t->left);
        if(t->right)
            a.push(t->right);
    }
    while(!b.empty()){
        node*t=b.top();
        b.pop();
        cout<<t->val<<' ';
    }
    cout<<endl;
}


void post(node*root){
    if(root){
        post(root->left);
        post(root->right);
        cout<<root->val<<' ';
    }
}

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    node* root=nn(a[0]);
    for(int i=1;i<n;i++)
        insert(root,a[i]);

    post_2_stack(root);
    post(root);


}
