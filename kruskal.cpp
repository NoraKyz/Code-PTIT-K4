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

ll t, n, m;
ll parent[105], size[105];

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

ll find_set(ll v) {
    if (v == parent[v]) 
        return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(ll a, ll b) 
{
    a = find_set(a);
    b = find_set(b);

    if (a != b) 
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];

        return 1;
    }

    return 0;
}

struct Edge
{
    ll x, y, w;
};

bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}

vector<Edge> v;

ll Kruskal() 
{
    ll res = 0;
    for(auto it : v)
    {
        if(union_sets(it.x, it.y))
            res += it.w;
    }

    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        memset(parent, 0, sizeof(parent));
        memset(size, 0, sizeof(size));
        v.clear();

        cin >> n >> m;

        FOR(i,1,n,1) make_set(i);

        FOR(i,1,m,1) 
        {
            ll x, y, w;
            cin >> x >> y >> w;
            
            Edge e = {x, y, w};
            v.pb(e);
        }

        sort(all(v), comp);

        cout << Kruskal() << '\n';
    }
    
    return 0;
}