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
vector<ll> adj[2001];
ll visited[2001];

bool DFS(ll u)
{
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v]) 
        {
            if(DFS(v)) return 1;
        }
        else if(visited[v] == 1) return 1;
    }
    
    visited[u] = 2;
    return 0;
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        FOR(i,1,n,1) 
        {
            visited[i] = 0;            
            adj[i].clear();
        }

        bool kt = 0;
        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }

        FOR(i,1,n,1) 
        {
            if(!visited[i]) 
            {
                if(DFS(i))
                {
                    kt = 1;
                    break;
                }              
            }
        }

        cout << (kt ? "YES" : "NO") << '\n'; 
    }
    return 0;
}