#include <iostream>
using namespace std;

struct node{
    int val,count,visited;
    node *left,*right,*next;
};

node* nn(int val) {
    node *t = new node;
    t->val = val;
    t->left = t->right = t->next = NULL;
    t->count = 0;
    t->visited=0;
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


void morris_post(node* root){
    while(root) {
        if(root->visited) {
            cout<<root->val<<' ';
            root = root->next;
            continue;

        }

        root->visited=1;
        if(!root->left && !root->right) {
            cout << root->val << ' ';
            root=root->next;
        }

        else if(root->left && root->right){
            root->left->next=root->right;
            root->right->next=root;
            root=root->left;
        }

        else if(!root->left){
            root->right->next=root;
            root=root->right;
        }

        else {
            root->left->next=root;
            root=root->left;
        }
    }


}

void post(node*root){
    if(root){
        post(root->left);
        post(root->right);
        cout<<root->val<<' ';
    }
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

    cout<<"post order traversal"<<endl;
    morris_post(root);
    cout<<endl;
    post(root);

}
