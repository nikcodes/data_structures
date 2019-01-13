#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define ll long long int
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define vfor(e, a) for (vector<ll> :: iterator e = a.begin(); e != a.end(); e++)
#define forr(i, n) for (ll i = 0; i < n; i++)
#define rfor(i, n) for (ll i = n - 1; i >= 0; i--)
#define fors(i, b, e, steps) for(ll i = b; i <= e; i += steps)
#define rfors(i, e, b, steps) for(ll i = e; i >= b; i -= steps)
#define mp make_pair
using namespace std;

bool prime[1];

void sieve(ll n){
    fill(prime, prime + n + 1, true);
    prime[1] = false;
    prime[0] = false;
    fors(i, 2, n, 1){
        if (prime[i]){
            fors(j, i + i, n, i){
                prime[j] = false;
            }
        }
    }
}


//This function returns the height of node u whose parent is v
ll height(vector<ll> a[], ll u, ll v){
    ll h = 0;
    for (auto e : a[u]){
        if (e != v){
            h = max(h, height(a, e, u));
        }
    }

    return h + 1;
}

//This function returns the largest path length of which u is a part but not v, formally diameter
ll dfs(vector<ll> a[], ll u, ll v){
    ll max1 = 0, max2 = 0;
    ll h = 0;
    for (auto e : a[u]){
        if (e != v){
            h = height(a, e, u);
            if (h >= max1){
                max2 = max1;
                max1 = h;
            }

            else{
                max2 = max(max2, h);
            }
        }
    }

    return max1 + max2 + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<ll> a[n];
    forr(i, m){
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    ll ans = INT_MIN;

    forr(i, n){
        for (auto j : a[i]){

            //Consider edge between i and j is erased and then find the largest path that contains i. Similarly find for j.
            //These two paths not intersect so find their product and update the ans
            //In short we just need to find the diameter of the two graphs

            ll left = 0, right = 0;

            left = dfs(a, i, j);
            right = dfs(a, j, i);

            ans = max(ans, left * right);

        }
    }

    cout << '\n';
    cout << ans;

}
