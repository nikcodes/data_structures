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

//Bellman Ford

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isLower(char c){
    return 97 <= c && c <= 122;
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    cout << setprecision(10);


    ll n, m, u, v, w;
    cin >> n >> m;
    vector<ll> a[2 * m];


    forr(i, m){
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }

    ll source;
    cin >> source;

    ll dist[n];
    fill(dist, dist + n, INT_MAX);
    dist[source] = 0;

    forr(i, n - 1){
        forr(j, m){
            u = a[j][0], v = a[j][1], w = a[j][2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    forr(j, m){
        u = a[j][0], v = a[j][1], w = a[j][2];
        if (dist[u] + w < dist[v]){
            cout << "Negative weight cycle";
            return 0;
        }
    }

    cout << "No negative weight cycle" << '\n';
    for(auto e : dist){
        cout << e << ' ';
    }

}
