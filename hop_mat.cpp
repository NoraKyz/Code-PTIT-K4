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

ll t, n, m, k;
vector<ll> adj[1005], v;
bool visited[1005] = {0};
unordered_map<ll, ll> mp;

void DFS(ll u)
{
    visited[u] = 1;
    mp[u]++;

    for(ll v : adj[u])
    {
        if(!visited[v]) DFS(v);
    }
}
   
int main()
{   
    fast_cin
    
    {
        mp.clear();

        cin >> k >> n >> m;

        FOR(i,1,k,1)
        {
            ll x;
            cin >> x;
            v.pb(x);
        }

        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }

        for(auto it : v) 
        {
            memset(visited, 0, sizeof(visited));
            DFS(it);
        }

        ll res = 0;

        for(auto it : mp)
        {
            if(it.se == k) res ++;
        }

        cout << res << '\n';

        FOR(i,1,n,1) adj[i].clear();    
    }
    return 0;
}