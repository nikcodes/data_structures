#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
#define mod 1000000007
#define pi 3.141592653589793
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define vfor(e, a) for (vector<ll> :: iterator e = a.begin(); e != a.end(); e++)
#define vfind(a, e) find(a.begin(), a.end(), e)
#define forr(i, n) for (ll i = 0; i < n; i++)
#define rfor(i, n) for (ll i = n - 1; i >= 0; i--)
#define fors(i, b, e, steps) for(ll i = b; i < e; i += steps)
#define rfors(i, e, b, steps) for(ll i = e; i > b; i -= steps)
#define mp make_pair
using namespace std;

// Kosaraju’s algorithm for strongly connected components

stack<ll> s;
void dfs(vector<ll> a[], bool visited[], ll u) {
    visited[u] = true;
    for (auto e : a[u]) {
        if (!visited[e]) {
            dfs(a, visited, e);
        }
    }

    s.push(u);
}

void dfs2(vector<ll> a[], bool visited[], ll u){
    cout << u << ' ';
    visited[u] = true;
    for (ll e : a[u]) {
        if (!visited[e]) {
            dfs2(a, visited, e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    cout << setprecision(10);


    ll n, m;
    ll u, v;
    cin >> n >> m;
    vector<ll> a[n];
    forr(i, m) {
        cin >> u >> v;
        a[u].pb(v);
    }

    bool visited[n];
    fill(visited, visited + n, false);
    forr (i, n) {
        if (!visited[i]) {
            dfs(a, visited, i);
        }
    }

    vector<ll> b[n];
    forr(i, n) {
        for(auto e : a[i]) {
            b[e].pb(i);
        }
    }
    fill(visited, visited + n, false);

    cout << "Strongly connected components are";
    while (!s.empty()) {
        ll e = s.top();
        s.pop();

        if (!visited[e]) {
            cout << '\n';
            dfs2(b, visited, e);
        }
    }
}



//7 8
//0 1
//2 3
//3 0
//5 6
//2 4
//1 2
//4 5
//6 
