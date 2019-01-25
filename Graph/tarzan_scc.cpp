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

//Print all Strongly Connected Components

ll t = 1;
stack<ll> s;
void dfs(vector<ll> a[], ll u, ll disc[], ll low[], bool stackMember[]) {
    disc[u] = low[u] = t;
    t++;
    s.push(u);
    stackMember[u] = true;

    for (auto v : a[u]) {
        if (disc[v] == -1) {
            dfs(a, v, disc, low, stackMember);
            low[u] = min(low[u], low[v]);
        }

        //update the low value of u only if v is in current stack
        else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    //check if u is the first node to be discovered in the scc it belong to
    if (disc[u] == low[u]) {
        ll top = -1;
        while (top != u) {
            top = s.top();
            s.pop();
            cout << top << ' ';
            stackMember[top] = false;
        }

        cout << '\n';
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
    }

    ll disc[n], low[n];
    fill(disc, disc + n, -1);
    fill(low, low + n, -1);

    bool stackMember[n];
    fill(stackMember, stackMember + n, false);

    cout << "SSC components are\n";
    forr(i, n) {
        if (disc[i] == -1){
            dfs(a, i, disc, low, stackMember);
        }
    }
}

//11 17
//0 1
//0 3
//1 2
//1 4
//2 0
//2 6
//3 2
//4 5
//4 6
//5 6
//5 7
//5 8
//5 9
//6 4
//7 9
//8 9
//9 8
