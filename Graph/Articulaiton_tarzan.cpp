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

//Articulation point
set<ll> articulation;

ll t = 0;
void dfs(vector<ll> a[], ll u, bool visited[], ll disc[], ll low[], ll parent[]) {
    visited[u] =true;
    t++;
    disc[u] = low[u] = t;
    ll child = 0;
    for(auto v : a[u]) {
        if (!visited[v]) {
            child++;
            parent[v] = u;
            dfs(a, v, visited, disc, low, parent);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && child > 1) {
                articulation.insert(u);
            }

            else if (parent[u] != -1 && disc[u] <= low[v]) {
                articulation.insert(u);
            }
        }

        else if (parent[u] != v) {
            low[u] = min(low[u], disc[v]);
        }
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    cout << setprecision(10);

    ll n, m;
    cin >> n >> m;
    vector<ll>  a[n];
    forr(i, m){
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    ll disc[n], low[n], parent[n];
    bool visited[n];
    fill(visited, visited + n, false);
    fill(parent, parent + n, -1);

    forr(i, n){
        if (!visited[i]){
            dfs(a, i, visited, disc, low, parent);
        }
    }

    for (auto e : articulation) {
        cout << e << ' ';
    }
}
