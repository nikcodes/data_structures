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

bool comp(vector<ll> a, vector<ll> b) {
    return a[2] <= b[2];
}


struct node {
    ll val;
    ll rank;
    node* parent;
};

map<ll, node*> d;


node* findParent (node* a) {
    if (a->parent == a) {
        return a;
    }

    a->parent = findParent(a->parent);
    return a->parent;
}

void doUnion(node* a, node* b) {
    node* p1 = findParent(a);
    node* p2 = findParent(b);
    if (p1 == p2) {
        cout << "In same subset";
    }

    else {
        if (p1->rank > p2->rank) {
            p2->parent = p1;
        }

        else if (p1->rank == p2->rank) {
            p2->parent = p1;
            p1->rank++;
        }

        else {
            p1->parent = p2;
        }
    }
}

node* make (ll val) {
    node* n = new node;
    n->val = val;
    n->rank = 0;
    n->parent = n;
    return n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);

    ll n, m;
    cin >> n >> m;
    vector<ll> a[m];
    forr(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
        d[u] = make(u);
        d[v] = make(v);
    }

    sort(a, a + m, comp);
    ll edge = 0;
    vector<ll> edges[n - 1];
    ll i = 0;
    ll totalW = 0;
    while (edge < n - 1) {
        ll u = a[i][0];
        ll v = a[i][1];
        ll w = a[i][2];
        node* p1 = findParent(d[u]);
        node* p2 = findParent(d[v]);
        if (p1 != p2) {
            edges[edge] = {u, v};
            edge++;
            doUnion(d[u], d[v]);
            totalW += w;
        }

        i++;
    }

    cout << "Total weight of the MSP is " << totalW << '\n';
    for (auto e : edges) {
        cout << e[0] << ' ' << e[1] << '\n';
    }

}
