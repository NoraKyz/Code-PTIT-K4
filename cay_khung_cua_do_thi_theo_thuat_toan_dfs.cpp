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

ll t, n, m, st;
vector<pair<ll,ll>> e;
vector<ll> adj[2001];
bool visited[2001];

void dfs(ll u)
{
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v]) 
        {
            e.push_back({u,v});
            dfs(v);
        }
    }
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        FOR(i,1,n,1) 
        {
            adj[i].clear();
            visited[i] = 0;
        }
        e.clear();

        cin >> n >> m >> st;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        bool kt = 1;
        dfs(st);
        FOR(i,1,n,1) if(!visited[i]) kt = 0;

        if(kt) 
        {
            for(auto i : e) cout << i.fi << ' ' << i.se << '\n';  
        }
        else cout << -1 << '\n';
    }
    return 0;
}