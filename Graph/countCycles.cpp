#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
#define mod 1000000007
#define pi 3.141592653589793
#define f first
#define s second
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

ll cycles;
void dfs(ll start, ll cur, ll dist, bool visited[], vector<ll> a[], ll k, vector<ll> path){
    if (dist == k){
        if (vfind(a[cur], start) != a[cur].end()){
            cycles++;
            for (auto e : path){
                cout << e << ' ';
            }
            cout << cur << '\n';
        }
        return;
    }

    visited[cur] = true;
    path.pb(cur);

    for (auto e : a[cur]){
        if (!visited[e]){
            dfs(start, e, dist + 1, visited, a, k, path);
        }
    }

    visited[cur] = false;
    path.pob();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);


    ll n, m;
    cin >> n >> m;
    vector<ll> a[n];
    forr (i, m){
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    cycles = 0;
    bool visited[n];
    fill(visited, visited + n, false);
    ll size = 4;
    vector<ll> path;
    forr (i, n - size + 1){
        dfs(i ,i , 1, visited, a, size, path);
        visited[i] = true;
    }

    cout << cycles / 2;
}
