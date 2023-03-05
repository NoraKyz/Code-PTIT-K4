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

ll t, n;
vector<ll> adj[10001];
bool visited[10001] = {0};

void DFS(ll u)
{
    cout << u << " ";
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v]) 
        {
            DFS(v);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll v, e, u;
        cin >> v >> e >> u;
        FOR(i,1,e,1) 
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        DFS(u);
        cout << '\n';

        FOR(i,1,v,1) adj[i].clear();
        memset(visited,0,sizeof(visited));
    }
    
    return 0;
}