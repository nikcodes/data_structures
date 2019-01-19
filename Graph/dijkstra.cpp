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


void up(pair<ll, ll> a[], ll n, ll i, ll indArray[]) {
    ll ind = (i - 1) / 2;
    while (ind >= 0 && a[ind].s > a[i].s) {
        swap(a[ind], a[i]);

        indArray[a[ind].f] = ind;
        indArray[a[i].f] = i;

        i = ind;
        ind = (i - 1) / 2;
    }
}

void down(pair<ll, ll> a[], ll n, ll i, ll indArray[]) {
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;
    ll m = a[i].s;
    ll ind = i;

    if (left < n && a[left].s < m) {
        ind = left;
        m = a[left].s;
    }

    if (right < n && a[right].s < m) {
        ind = right;
    }

    if (ind != i) {
        swap(a[i], a[ind]);
        indArray[a[i].f] = i;
        indArray[a[ind].f] = ind;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    cout << setprecision(10);


    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a[n];
    forr(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));

    }

    ll parent[n];
    parent[0] = -1;

    pair<ll, ll> dist[n];
    forr(i, n) {
        dist[i] = mp(i, INT_MAX);
    }
    dist[0].s = 0;

    ll ind[n];
    iota(ind, ind + n, 0);

    ll ans[n];
    ans[0] = 0;

    bool visited[n];
    fill(visited, visited + n, false);

    ll size = n;
    forr(i, n) {
        ll u = dist[0].f;
        visited[u] = true;
        ll d1 = dist[0].s;
        ans[u] = dist[0].s;
        swap(dist[0], dist[size - 1]);
        size--;
        down(dist, size, 0, ind);

        for (auto e : a[u]) {
            if (visited[e.f]){
                continue;
            }

            ll v = e.f;
            ll j = ind[v];
            if (dist[j].s > d1 + e.s) {
                dist[j].s = d1 + e.s;
                up(dist, size, j, ind);
                parent[v] = u;
            }
        }
    }

    stack<ll> st;
    forr(i, n) {
        ll j = i;
        while (j != -1) {
            st.push(j);
            j = parent[j];
        }

        while (!st.empty()) {
            cout << st.top() << "->";
            st.pop();
        }
        cout << "   Path length is " << ans[i];
        cout << '\n';
    }
}

//9 14
//7 6 1
//8 2 2
//6 5 2
//0 1 4
//2 5 4
//8 6 6
//2 3 7
//7 8 7
//0 7 8
//1 2 8
//3 4 9
//5 4 10
//1 7 11
//3 5 14
