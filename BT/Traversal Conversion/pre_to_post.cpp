//post order from preorder

#include <iostream>
#include <limits.h>
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


void post(int a[],int n,int l,int r){
    //first check if array is finished
    if(i==n)
        return;

    //asign the root
    int root=a[i];

    //if root is valid according to the constraints then form the left and right subtrees
    if(l<root && root<r){
        i++;
        post(a,n,l,root);
        post(a,n,root,r);
        cout<<root<<' ';
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    post(a,n,INT_MIN,INT_MAX);
    cout<<endl;
}
