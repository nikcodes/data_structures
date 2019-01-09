#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
using namespace std;

void dfs(ll u, bool visited[], vector<ll> a[]){
    visited[u] = true;
    for (auto e = a[u].begin(); e != a[u].end(); e++){
        if (!visited[*e]){
            dfs(*e, visited, a);
        }
    }
}

void checkMother(ll mother, vector<ll> a[], ll n){
    bool visited[n + 1];
    fill(visited, visited + n + 1, false);
    visited[0] = true;
    visited[mother] = true;
    for (auto e = a[mother].begin(); e != a[mother].end(); e++){
        dfs(*e, visited, a);
    }

    if (any_of(visited, visited + n + 1, [] (bool t) {return t == false;})){
        cout << "No Mother vertex ";
    }

    else{
        cout << "Mother vertex is " << mother;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n, u, v;
    cin >> n;
    vector<ll> a[n + 1];

    for (ll i = 0; i < n; i++){
        cin >> u >> v;
        a[u].push_back(v);
    }

    bool visited[n + 1];
    fill(visited, visited + n + 1, false);
    ll last = -1;


    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i, visited, a);
            last = i;
        }
    }

    cout << last << '\n';
    checkMother(last, a, n);


}
