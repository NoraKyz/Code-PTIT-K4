#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n, m, q;
ll parent[1001], sz[1001];

void make_set(ll v) {
    parent[v] = v;
    sz[v] = 1;
}

ll find_set(ll v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) 
    {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b]; 
    } 
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));

        bool kt = 0;

        cin >> n >> m;

        FOR(i,1,n,1) make_set(i); 

        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            if(find_set(x) == find_set(y)) kt = 1;
            else union_sets(x, y);
        }

        cout << (kt ? "YES" : "NO") << '\n';

    }
    return 0;
}