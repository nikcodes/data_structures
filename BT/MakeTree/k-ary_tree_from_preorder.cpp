//Construct the full k-ary tree from its preorder traversal
#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int val,done;
    vector<node*>child;

};

node* nn(int val){
    node* t = new node;
    t->val=val;
    t->done=0;
    return t;
}


node* form(int a[],int n,int k,int depth){
    stack<node*>s;
    node *root=nn(a[0]), *t, *cur;
    s.push(root);
    int h=2;
    for(int i=1;i<n;i++){
        cur=nn(a[i]);
        t=s.top();
        t->child.push_back(cur);
        t->done++;

        //if all the children of the node at the top of the stack are been asigned then pop the top node and decrease the level
        if(t->done==k){
            s.pop();
            h--;
        }

        //if the level is not the last level then add the current node to the stack increasing the level
        else if(h<depth){
            s.push(cur);
            h++;
        }
    }
    return root;
}

void level(node*root) {
    vector<node *> a, b;
    a.push_back(root);
    while (!a.empty()) {
        for (auto e:a) {
            cout << e->val<<' ';
            for (auto f:e->child)
                b.push_back(f);

        }
        cout<<endl;
        a = b;
        b.clear();
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int height = (int)ceil(log((double)n * (k - 1) + 1)
                           / log((double)k));

    node*root=form(a,n,k,height);
    cout<<"The level order traversal of the tree is"<<endl;
    level(root);
}
