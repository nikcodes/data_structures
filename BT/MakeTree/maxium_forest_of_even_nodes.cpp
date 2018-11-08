/*
 * Convert a tree to forest of even nodes
Given a tree of n even nodes. The task is to find the maximum number of edges to be removed from the given tree to obtain forest of trees having even number of nodes.
 This problem is always solvable as given graph has even nodes.
 Input will be given as
 n:number of adges
 next n lines that shows the edges
 */


#include<iostream>
#include<vector>
using namespace std;



int dfs(vector<int>a[],int n,int visited[],int node,int &ans){
    int odd = 1,child;
    auto ar = a[node];
    for (auto e = ar.begin(); e != ar.end(); e++) {
        if(visited[*e]==0) {
            child = dfs(a, n, visited, *e, ans);
            (child % 2) ? (odd += child) : (ans++);
        }
    }
    return odd;

}


int main(){
    int n,u,v;
    cin>>n;
    vector<int> a[n+1];
    for(int i=0;i<n;i++){
        cin>>u>>v;
        a[u].push_back(v);
    }
    int ans=0;
    int visited[n]={0};
    dfs(a,n,visited,1,ans);
    cout<<"maximum divisions that can be made are"<<endl;
    cout<<ans;


}




//9
//2 5
//3 6
//4 7
//4 8
//5 10
//1 2
//1 3
//5 9
//1 4
