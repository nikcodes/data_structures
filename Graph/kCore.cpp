#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
using namespace std;

bool dfs(ll u, bool visited[], vector<ll> a[], ll degree[], ll k){
    visited[u] = true;
    for (auto e = a[u].begin(); e != a[u].end(); e++){
        if (degree[u] < k){
            //u has to be deleted so degree of e will be decremented
            degree[*e]--;
        }

        //Recur for e if its not visited so far and check if updated degree of e is less than k
        if (dfs(*e, visited, a, degree, k)){
            //e also needs to be deleted
            degree[u]--;
        }
    }

    return degree[u] < k;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n, m, u, v;
    cin >> n >> m;
    vector<ll> a[n + 1];

    for (ll i = 0; i < m; i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bool visited[n + 1];
    fill(visited, visited + n + 1, false);

    ll degree[n + 1];
    for (ll i = 0; i <= n; i++){
        degree[i] = a[i].size();
    }


    for (ll i = 0; i <= n; i++){
        if (!visited[i]){
            dfs(i, visited, a, degree, 3);
        }
    }
    
    cout << "Vertices that will not be deleted are \n";
    for (ll i = 0; i <= n; i++){
        if (degree[i] >= 3){
            cout << i << ' ';
        }
    }
    
}
