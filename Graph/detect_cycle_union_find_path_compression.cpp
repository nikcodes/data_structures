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

struct node{
    node* parent;
    int val;
    int rank;
};

map<int, node*> d;

node* make(int val) {
    node* newNode = new node;
    newNode->val = val;
    newNode->rank = 0;
    newNode->parent = newNode;
    return newNode;
}

node* findset(node* n) {
    if (n->parent == n) {
        return n;
    }

    n->parent = findset(n->parent);
    return n->parent;
}

void dounion(node* a, node* b) {
    if (a->parent == b->parent){
        cout << "Both belong to same subset" << '\n';
        return;
    }

    node* p1 = findset(a);
    node* p2 = findset(b);
    if (p1->rank >= p2->rank) {
        p2->parent = p1;
        p1->rank = (p1->rank == p2->rank) ? p1->rank + 1 : p1->rank;
    }

    else {
        p1->parent = p2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);

    ll n, m;
    cin >> n >> m;
    vector<ll> a[n];
    forr(i, m) {
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        d[u] = make(u);
        d[v] = make(v);
    }

    forr(i, n) {
        for (auto e : a[i]) {
            auto p1 = findset(d[i]);
            auto p2 = findset(d[e]);
            if (p1 == p2) {
                cout << "cycle is present";
                return 0;
            }

            else {
                dounion(d[i], d[e]);
            }
        }
    }

    cout << "No cycle is present";

}
