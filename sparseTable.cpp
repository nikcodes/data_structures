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

ll b[100][100];

ll q(ll l, ll r){
    ll j = floor(log2(r - l));
    return min(b[l][j], b[r - (1 << j) + 1][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);

    ll n;
    cin >> n;
    ll a[n];
    forr(i, n){
        cin >> a[i];
    }

    ll total = floor(log2(n));

    forr(i, n){
        b[i][0] = a[i];
    }

    fors(j, 1, total + 1, 1){
        forr(i, n){
            b[i][j] = min(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
        }
    }

    cout << q(2, 3);
    
}
