#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define vfor(e, a) for (auto e = a.begin(); e != a.end(); e++)
#define FOR(i, n) for (auto i = 0; i < n; i++)
#define revfor(i, n) for (ll i = n - 1; i >= 0; i--)
#define fora(i, n, a) for (ll i = 0; i < n; i += a)
#define revfora(i, n, a) for (ll i = n - 1; i >= 0; i -= a)
#define mp make_pair
using namespace std;

ll paths;


void path(ll dest, ll v, vector<ll> a[], bool visited[], vector<ll> till){
    till.pb(v);
    if (dest == v){
        paths++;
        vfor(e, till){
            cout << *e << ' ';
        }
        cout << '\n';
        till.pob();
        return;
    }

    visited[v] = true;
    vfor (e, a[v]){
        if (!visited[*e]){
            path(dest, *e, a, visited, till);
        }
    }
    visited[v] = false;
    till.pob();
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<ll> a[n + 1];
    FOR(i, m){
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
    paths = 0;
    cout << "Enter the source and destination" << '\n';
    ll source, dest;
    cin >> source >> dest;

    bool visited[n + 1];
    fill(visited, visited + n, false);
    vector<ll> till = {source};
    visited[source] = true;
    for (auto e : a[source]) {
        path(dest, e, a, visited, till);
    }
    cout << '\n' << "total number of paths are " << paths << '\n';

}
